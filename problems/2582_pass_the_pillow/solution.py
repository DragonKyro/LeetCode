class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        cycle = 2 * (n - 1)
        time %= cycle
        return time + 1 if time < n else 2 * n - 1 - time
