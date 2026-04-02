class Solution:
    def topKFrequent(self, words: list[str], k: int) -> list[str]:
        from collections import Counter
        count = Counter(words)
        return sorted(count.keys(), key=lambda w: (-count[w], w))[:k]
