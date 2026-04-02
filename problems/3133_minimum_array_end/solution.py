class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        res = x
        bit = 0
        for i in range(64):
            if not (x >> i & 1):
                if n >> bit & 1:
                    res |= 1 << i
                bit += 1
        return res
