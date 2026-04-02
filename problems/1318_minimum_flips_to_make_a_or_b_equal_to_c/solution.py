class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        flips = 0
        for i in range(32):
            ba = (a >> i) & 1
            bb = (b >> i) & 1
            bc = (c >> i) & 1
            if bc == 1:
                if ba == 0 and bb == 0:
                    flips += 1
            else:
                flips += ba + bb
        return flips
