class Solution:
    def sumZero(self, n: int) -> list[int]:
        res = list(range(1, n))
        res.append(-sum(res))
        return res
