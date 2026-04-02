class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        from collections import Counter
        counts = Counter(s)
        return len(set(counts.values())) == 1
