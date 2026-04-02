class Solution:
    def waysToReachStair(self, k: int) -> int:
        from math import comb
        res = 0
        for jump in range(32):
            pos = 1 << jump
            down = pos - k
            if down < 0:
                continue
            if down > jump + 1:
                break
            res += comb(jump + 1, down)
        return res
