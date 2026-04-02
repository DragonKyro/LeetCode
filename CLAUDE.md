# CLAUDE.md

## Project Overview

Comprehensive LeetCode solutions repository: 1,559 problems solved in Python, Java, C++, and SQL.

## Key Files

- `leetcode_problems.xlsx` — Database of all 3,888 LeetCode problems (scraped via GraphQL API)
- `snippets.json` — Function signatures for all problems (gitignored, regenerable via `fetch_snippets.py`)
- `problems/` — One directory per problem with description, tests, and solutions
- `directory/` — Markdown index files by topic and difficulty
- `shared/` — Common data structures (ListNode, TreeNode) for Python/Java/C++
- `test_runner/run_tests.py` — Universal test runner

## Scripts

- `scrape_leetcode.py` — Scrape problems from LeetCode GraphQL API
- `fetch_snippets.py` — Fetch code snippets (function signatures)
- `generate_tests.py` — Parse examples + generate edge case tests
- `write_solutions.py` — Deploy solutions from `solutions_data/` to problem dirs

## Environment

- Python via conda env `arcade`
- Key packages: `requests`, `openpyxl`
- Platform: Windows 11

## Conventions

- Problem data sourced from LeetCode's public GraphQL API at `https://leetcode.com/graphql`
- Premium-gated problems recorded with basic metadata only
- Solutions follow LeetCode class format: `class Solution` with the expected method signature
- SQL problems use MySQL syntax
- `solutions_data/` contains batch JSON files (gitignored build artifacts); `write_solutions.py` deploys them
- Test cases with `"expected": "__VERIFY__"` are edge cases without known answers
- Scrapers save checkpoints every 50 problems for resume support (gitignored)
