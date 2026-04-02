class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        res = 0
        l = 0
        cnt = [0, 0]
        for r in range(n):
            cnt[int(s[r])] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[int(s[l])] -= 1
                l += 1
            res += r - l + 1
        return res
