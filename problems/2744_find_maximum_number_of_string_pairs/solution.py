from typing import List


class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        seen = set()
        count = 0
        for w in words:
            if w[::-1] in seen:
                count += 1
            seen.add(w)
        return count
