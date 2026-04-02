class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        from collections import Counter
        n = len(word)
        chunks = [word[i:i+k] for i in range(0, n, k)]
        cnt = Counter(chunks)
        return len(chunks) - max(cnt.values())
