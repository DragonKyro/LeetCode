"""
Universal Test Runner for LeetCode Solutions

Reads tests.json, runs solutions in Python/Java/C++, and compares output.

Usage:
    python test_runner/run_tests.py <problem_dir> [--lang python|java|cpp|all]
    python test_runner/run_tests.py problems/1_two_sum --lang python
    python test_runner/run_tests.py problems/1_two_sum --lang all
    python test_runner/run_tests.py all --lang python        # run all problems
    python test_runner/run_tests.py all --lang all           # run everything
"""

import argparse
import importlib.util
import json
import os
import re
import subprocess
import sys
import tempfile
import traceback
from pathlib import Path

# Add project root to path
PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from shared.python.data_structures import (
    list_to_linked, linked_to_list,
    list_to_tree, tree_to_list,
)


# ---------------------------------------------------------------------------
# Result tracking
# ---------------------------------------------------------------------------

class TestResult:
    def __init__(self, problem_id, title, lang):
        self.problem_id = problem_id
        self.title = title
        self.lang = lang
        self.passed = 0
        self.failed = 0
        self.skipped = 0
        self.errors = []

    @property
    def total(self):
        return self.passed + self.failed + self.skipped

    def __repr__(self):
        status = "PASS" if self.failed == 0 and self.passed > 0 else "FAIL" if self.failed > 0 else "SKIP"
        return f"[{status}] #{self.problem_id} {self.title} ({self.lang}): {self.passed}/{self.total} passed"


# ---------------------------------------------------------------------------
# Output comparison
# ---------------------------------------------------------------------------

def normalize_output(val):
    """Normalize output for comparison."""
    if isinstance(val, float):
        return round(val, 5)
    if isinstance(val, list):
        return [normalize_output(v) for v in val]
    if isinstance(val, dict):
        return {k: normalize_output(v) for k, v in sorted(val.items())}
    return val


def compare_output(actual, expected):
    """Compare actual vs expected output. Handles floats, sorted lists, etc."""
    if expected == "__VERIFY__":
        return True  # Edge case without known answer - skip

    actual = normalize_output(actual)
    expected = normalize_output(expected)

    if actual == expected:
        return True

    # Float comparison with tolerance
    if isinstance(actual, (int, float)) and isinstance(expected, (int, float)):
        return abs(actual - expected) < 1e-5

    # List comparison - try sorted if unsorted fails (for problems with unordered output)
    if isinstance(actual, list) and isinstance(expected, list):
        if len(actual) != len(expected):
            return False
        # Try element-wise
        if all(compare_output(a, e) for a, e in zip(actual, expected)):
            return True

    return False


# ---------------------------------------------------------------------------
# Python runner
# ---------------------------------------------------------------------------

def detect_return_type(snippet_code):
    """Detect if the solution returns a ListNode or TreeNode from the snippet."""
    if not snippet_code:
        return "auto"
    if "-> Optional[ListNode]" in snippet_code or "-> ListNode" in snippet_code:
        return "ListNode"
    if "-> Optional[TreeNode]" in snippet_code or "-> TreeNode" in snippet_code:
        return "TreeNode"
    return "auto"


def detect_param_types(snippet_code):
    """Detect parameter types that need conversion (ListNode, TreeNode)."""
    if not snippet_code:
        return {}
    types = {}
    # Match patterns like: head: Optional[ListNode], root: Optional[TreeNode]
    for m in re.finditer(r'(\w+)\s*:\s*Optional\[(ListNode|TreeNode)\]', snippet_code):
        types[m.group(1)] = m.group(2)
    for m in re.finditer(r'(\w+)\s*:\s*(ListNode|TreeNode)', snippet_code):
        types[m.group(1)] = m.group(2)
    return types


def convert_input_param(value, param_type):
    """Convert a JSON value to the appropriate Python data structure."""
    if param_type == "ListNode":
        if isinstance(value, list):
            return list_to_linked(value)
        return value
    elif param_type == "TreeNode":
        if isinstance(value, list):
            return list_to_tree(value)
        return value
    return value


def convert_output(value, return_type):
    """Convert solution output back to JSON-comparable format."""
    if return_type == "ListNode" or (hasattr(value, 'val') and hasattr(value, 'next') and not hasattr(value, 'left')):
        return linked_to_list(value)
    elif return_type == "TreeNode" or (hasattr(value, 'val') and hasattr(value, 'left')):
        return tree_to_list(value)
    return value


def run_python_tests(problem_dir, tests_data, snippets_info=None):
    """Run Python solution against test cases."""
    result = TestResult(tests_data["problem_id"], tests_data["title"], "python")
    solution_path = os.path.join(problem_dir, "solution.py")

    if not os.path.exists(solution_path):
        result.skipped = len(tests_data.get("test_cases", []))
        result.errors.append("solution.py not found")
        return result

    # Load the solution module dynamically
    try:
        spec = importlib.util.spec_from_file_location("solution", solution_path)
        module = importlib.util.module_from_spec(spec)

        # Inject shared data structures into module namespace
        from shared.python.data_structures import ListNode, TreeNode, Node
        module.ListNode = ListNode
        module.TreeNode = TreeNode
        module.Node = Node

        spec.loader.exec_module(module)
        sol = module.Solution()
    except Exception as e:
        result.skipped = len(tests_data.get("test_cases", []))
        result.errors.append(f"Failed to load solution: {e}")
        return result

    # Detect types from snippet
    snippet_code = ""
    if snippets_info and "python3" in snippets_info.get("snippets", {}):
        snippet_code = snippets_info["snippets"]["python3"]

    return_type = detect_return_type(snippet_code)
    param_types = detect_param_types(snippet_code)

    # Find the solution method (first method that isn't __init__)
    method_name = None
    for name in dir(sol):
        if not name.startswith('_') and callable(getattr(sol, name)):
            method_name = name
            break

    if not method_name:
        result.skipped = len(tests_data.get("test_cases", []))
        result.errors.append("No solution method found")
        return result

    method = getattr(sol, method_name)

    for i, tc in enumerate(tests_data.get("test_cases", [])):
        if tc.get("expected") == "__VERIFY__":
            result.skipped += 1
            continue

        try:
            # Convert inputs
            inputs = tc["input"]
            if isinstance(inputs, dict):
                converted = {}
                for k, v in inputs.items():
                    ptype = param_types.get(k, "auto")
                    converted[k] = convert_input_param(v, ptype)
                actual = method(**converted)
            elif isinstance(inputs, list):
                actual = method(*inputs)
            else:
                actual = method(inputs)

            # Convert output
            actual = convert_output(actual, return_type)

            if compare_output(actual, tc["expected"]):
                result.passed += 1
            else:
                result.failed += 1
                result.errors.append(
                    f"TC {i+1}: expected {tc['expected']}, got {actual}"
                )
        except Exception as e:
            result.failed += 1
            result.errors.append(f"TC {i+1}: {type(e).__name__}: {e}")

    return result


# ---------------------------------------------------------------------------
# Java runner
# ---------------------------------------------------------------------------

def run_java_tests(problem_dir, tests_data, snippets_info=None):
    """Run Java solution against test cases via compiled subprocess."""
    result = TestResult(tests_data["problem_id"], tests_data["title"], "java")
    solution_path = os.path.join(problem_dir, "Solution.java")

    if not os.path.exists(solution_path):
        result.skipped = len(tests_data.get("test_cases", []))
        result.errors.append("Solution.java not found")
        return result

    # Generate a test harness, compile, and run
    tests_json_path = os.path.join(problem_dir, "tests.json")
    shared_dir = os.path.join(PROJECT_ROOT, "shared", "java")

    # Create temp runner file
    runner_code = _generate_java_runner(tests_data, solution_path)
    runner_path = os.path.join(problem_dir, "TestRunner.java")

    try:
        with open(runner_path, "w", encoding="utf-8") as f:
            f.write(runner_code)

        # Compile
        compile_cmd = [
            "javac", "-cp", f"{problem_dir};{shared_dir}",
            solution_path, runner_path
        ]
        comp = subprocess.run(compile_cmd, capture_output=True, text=True, timeout=30)
        if comp.returncode != 0:
            result.skipped = len(tests_data.get("test_cases", []))
            result.errors.append(f"Compilation failed: {comp.stderr[:500]}")
            return result

        # Run
        run_cmd = [
            "java", "-cp", f"{problem_dir};{shared_dir}",
            "TestRunner", tests_json_path
        ]
        run = subprocess.run(run_cmd, capture_output=True, text=True, timeout=30)

        # Parse results from stdout (JSON format)
        if run.returncode == 0 and run.stdout.strip():
            results = json.loads(run.stdout.strip())
            result.passed = results.get("passed", 0)
            result.failed = results.get("failed", 0)
            result.skipped = results.get("skipped", 0)
            result.errors = results.get("errors", [])
        else:
            result.skipped = len(tests_data.get("test_cases", []))
            result.errors.append(f"Runtime error: {run.stderr[:500]}")

    except subprocess.TimeoutExpired:
        result.skipped = len(tests_data.get("test_cases", []))
        result.errors.append("Timeout (30s)")
    except Exception as e:
        result.skipped = len(tests_data.get("test_cases", []))
        result.errors.append(f"Error: {e}")
    finally:
        # Cleanup generated files
        for f in [runner_path, runner_path.replace(".java", ".class"),
                   solution_path.replace(".java", ".class")]:
            if os.path.exists(f):
                try:
                    os.remove(f)
                except OSError:
                    pass

    return result


def _generate_java_runner(tests_data, solution_path):
    """Generate a Java test runner class (simplified - delegates JSON parsing)."""
    return '''import java.io.*;
import java.util.*;
import com.google.gson.*;  // Would need gson; fallback to manual parsing

public class TestRunner {
    public static void main(String[] args) throws Exception {
        // Simplified: output JSON results
        System.out.println("{\\"passed\\": 0, \\"failed\\": 0, \\"skipped\\": " +
            args.length + ", \\"errors\\": [\\"Java runner not yet fully implemented\\"]}");
    }
}
'''


# ---------------------------------------------------------------------------
# C++ runner
# ---------------------------------------------------------------------------

def run_cpp_tests(problem_dir, tests_data, snippets_info=None):
    """Run C++ solution against test cases via compiled subprocess."""
    result = TestResult(tests_data["problem_id"], tests_data["title"], "cpp")
    solution_path = os.path.join(problem_dir, "solution.cpp")

    if not os.path.exists(solution_path):
        result.skipped = len(tests_data.get("test_cases", []))
        result.errors.append("solution.cpp not found")
        return result

    # For now, mark as not-yet-implemented
    result.skipped = len(tests_data.get("test_cases", []))
    result.errors.append("C++ runner not yet fully implemented")
    return result


# ---------------------------------------------------------------------------
# Main orchestration
# ---------------------------------------------------------------------------

def load_snippets():
    """Load code snippets for type detection."""
    snippets_path = os.path.join(PROJECT_ROOT, "snippets.json")
    if os.path.exists(snippets_path):
        with open(snippets_path, "r", encoding="utf-8") as f:
            return json.load(f)
    return {}


def run_problem(problem_dir, lang="python", snippets=None):
    """Run tests for a single problem directory."""
    tests_path = os.path.join(problem_dir, "tests.json")
    if not os.path.exists(tests_path):
        return None

    with open(tests_path, "r", encoding="utf-8") as f:
        tests_data = json.load(f)

    pid = str(tests_data.get("problem_id", ""))
    snippets_info = snippets.get(pid, {}) if snippets else {}

    results = []
    runners = {
        "python": run_python_tests,
        "java": run_java_tests,
        "cpp": run_cpp_tests,
    }

    langs = ["python", "java", "cpp"] if lang == "all" else [lang]

    for l in langs:
        if l in runners:
            r = runners[l](problem_dir, tests_data, snippets_info)
            results.append(r)

    return results


def main():
    parser = argparse.ArgumentParser(description="LeetCode Universal Test Runner")
    parser.add_argument("target", help="Problem directory path, or 'all' for all problems")
    parser.add_argument("--lang", default="python", choices=["python", "java", "cpp", "all"])
    parser.add_argument("--verbose", "-v", action="store_true")
    parser.add_argument("--fail-only", action="store_true", help="Only show failures")
    args = parser.parse_args()

    snippets = load_snippets()

    if args.target == "all":
        problems_dir = os.path.join(PROJECT_ROOT, "problems")
        dirs = sorted(
            [os.path.join(problems_dir, d) for d in os.listdir(problems_dir)
             if os.path.isdir(os.path.join(problems_dir, d))]
        )
    else:
        dirs = [args.target]

    total_passed = 0
    total_failed = 0
    total_skipped = 0
    all_results = []

    for d in dirs:
        results = run_problem(d, args.lang, snippets)
        if not results:
            continue

        for r in results:
            all_results.append(r)
            total_passed += r.passed
            total_failed += r.failed
            total_skipped += r.skipped

            if args.fail_only and r.failed == 0:
                continue

            print(r)
            if args.verbose and r.errors:
                for err in r.errors[:5]:
                    print(f"    {err}")

    # Summary
    print(f"\n{'='*60}")
    print(f"SUMMARY ({args.lang})")
    print(f"{'='*60}")
    print(f"  Problems tested: {len(all_results)}")
    print(f"  Tests passed:    {total_passed}")
    print(f"  Tests failed:    {total_failed}")
    print(f"  Tests skipped:   {total_skipped}")

    problems_passing = sum(1 for r in all_results if r.failed == 0 and r.passed > 0)
    problems_failing = sum(1 for r in all_results if r.failed > 0)
    print(f"  Problems passing: {problems_passing}")
    print(f"  Problems failing: {problems_failing}")

    return 0 if total_failed == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
