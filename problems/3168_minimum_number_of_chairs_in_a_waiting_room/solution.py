class Solution:
    def minimumChairs(self, s: str) -> int:
        cur = res = 0
        for c in s:
            if c == 'E': cur += 1
            else: cur -= 1
            res = max(res, cur)
        return res
