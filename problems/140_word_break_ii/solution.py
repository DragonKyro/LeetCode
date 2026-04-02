from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        memo = {}
        def backtrack(start: int) -> List[str]:
            if start in memo:
                return memo[start]
            if start == len(s):
                return ['']
            result = []
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                if word in word_set:
                    for rest in backtrack(end):
                        result.append(word + (' ' + rest if rest else ''))
            memo[start] = result
            return result
        return backtrack(0)
