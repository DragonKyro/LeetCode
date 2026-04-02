from typing import List


class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        from collections import Counter
        count = Counter()
        for w in words:
            count += Counter(w)
        n = len(words)
        return all(v % n == 0 for v in count.values())
