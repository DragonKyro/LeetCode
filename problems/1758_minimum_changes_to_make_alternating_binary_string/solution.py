class Solution:
    def minOperations(self, s: str) -> int:
        count0 = sum(int(c) != i % 2 for i, c in enumerate(s))
        return min(count0, len(s) - count0)
