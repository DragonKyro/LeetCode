# CLAUDE.md

## Project Overview

This is a LeetCode solutions repository. The goal is to build a comprehensive compilation of LeetCode problem solutions.

## Key Files

- `leetcode_problems.xlsx` — Database of all 3,888 LeetCode problems (scraped via GraphQL API)
- `scrape_leetcode.py` — Web scraper that populates the Excel file; uses checkpoint/resume

## Environment

- Python via conda env `arcade`
- Key packages: `requests`, `openpyxl`, `pandas`
- Platform: Windows 11

## Conventions

- Problem data is sourced from LeetCode's public GraphQL API at `https://leetcode.com/graphql`
- Premium-gated problems are recorded with basic metadata only (number, title, difficulty, topics)
- The scraper saves checkpoints every 50 problems to `scrape_checkpoint.json` (gitignored)
