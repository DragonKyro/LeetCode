class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        cycle = 2 * (n - 1)
        k %= cycle
        return k if k < n else cycle - k
