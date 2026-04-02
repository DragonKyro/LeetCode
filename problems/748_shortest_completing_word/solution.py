from typing import List


class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        from collections import Counter
        target = Counter(c.lower() for c in licensePlate if c.isalpha())
        result = None
        for word in words:
            wc = Counter(word.lower())
            if all(wc[c] >= target[c] for c in target):
                if result is None or len(word) < len(result):
                    result = word
        return result
