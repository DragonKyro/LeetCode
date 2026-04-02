class Solution:
    def minSetSize(self, arr: list[int]) -> int:
        from collections import Counter
        counts = sorted(Counter(arr).values(), reverse=True)
        total = 0
        half = len(arr) // 2
        for i, c in enumerate(counts):
            total += c
            if total >= half:
                return i + 1
        return len(counts)
