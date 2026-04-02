class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        res = 10
        unique = 9
        avail = 9
        for i in range(2, min(n, 10) + 1):
            unique *= avail
            res += unique
            avail -= 1
        return res
