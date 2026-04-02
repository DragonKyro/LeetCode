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

## Scraper

`scrape_leetcode.py` fetches problem data from LeetCode's GraphQL API. Features:
- Fetches full problem list in batches
- Retrieves descriptions, hints, and topics for free problems
- Marks premium problems with available metadata
- Checkpoint/resume support for interrupted runs
- Exports to formatted Excel with filters and color-coding

### Usage

```bash
conda activate arcade
pip install requests openpyxl
python scrape_leetcode.py
```

## Solutions

Solutions will be organized by problem number and topic. (Coming soon)
