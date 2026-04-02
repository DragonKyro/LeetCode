# LeetCode

A comprehensive compilation of LeetCode solutions with a full problem database.

## Problem Database

`leetcode_problems.xlsx` contains all 3,888 LeetCode problems with:

| Column | Description |
|--------|-------------|
| Problem # | Frontend question number |
| Title | Problem title |
| Difficulty | Easy / Medium / Hard (color-coded) |
| Description | Full problem text with examples and constraints |
| Topics | Associated topics (Array, Hash Table, DP, etc.) |
| Hints | All available hints |
| Link | URL to original problem on LeetCode |
| Premium Only | Whether the problem requires LeetCode Premium |

**Breakdown:** 935 Easy | 2,033 Medium | 920 Hard | 761 Premium-gated

## Solutions

**1,559 problems solved** across multiple languages:

| Language | Solutions |
|----------|-----------|
| Python | 1,486 |
| Java | 1,486 |
| C++ | 1,486 |
| SQL | 73 |

Each problem directory contains:
- `problem.md` — full description with examples and constraints
- `tests.json` — test cases (parsed examples + generated edge cases)
- `solution.py` — Python solution
- `Solution.java` — Java solution
- `solution.cpp` — C++ solution
- `solution.sql` — SQL solution (database problems only)

## Directory Index

The `directory/` folder contains markdown files for each topic and difficulty level, with tables of problems linking to their `problem.md` files. Works as clickable navigation on GitHub.

- **By difficulty:** `easy.md`, `medium.md`, `hard.md`
- **By topic:** `array.md`, `dynamic_programming.md`, `binary_search.md`, etc. (70 topics)

## Test Runner

Run solutions against test cases:

```bash
# Test a single problem
python test_runner/run_tests.py problems/1_two_sum --lang python

# Test all problems
python test_runner/run_tests.py all --lang python

# Show only failures
python test_runner/run_tests.py all --lang python --fail-only -v
```

Supports Python natively. Java and C++ runners are scaffolded.

## Scraping & Generation Tools

| Script | Purpose |
|--------|---------|
| `scrape_leetcode.py` | Fetch all problems from LeetCode GraphQL API |
| `fetch_snippets.py` | Fetch function signatures (code snippets) |
| `generate_tests.py` | Parse examples and generate edge case test data |
| `write_solutions.py` | Deploy solutions from `solutions_data/` to problem dirs |

### Regenerating from scratch

```bash
conda activate arcade
pip install requests openpyxl

python scrape_leetcode.py          # Scrape problems -> leetcode_problems.xlsx
python fetch_snippets.py           # Fetch signatures -> snippets.json
python generate_tests.py           # Generate test files -> problems/*/tests.json
python write_solutions.py          # Deploy solutions -> problems/*/solution.*
```

## Shared Data Structures

`shared/` contains common LeetCode data structures for each language:
- `ListNode` — singly linked list node
- `TreeNode` — binary tree node
- `Node` — N-ary tree / graph node
- Serialization helpers (array <-> linked list, array <-> tree)
