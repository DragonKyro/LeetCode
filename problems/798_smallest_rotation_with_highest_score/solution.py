from typing import List


class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        change = [0] * (n + 1)
        for i in range(n):
            lo = (i + 1) % n
            hi = (i - nums[i] + n) % n
            change[lo] += 1
            change[(hi + 1) % n] -= 1
            if lo > hi:
                change[0] += 1
                change[hi + 1] -= 1
                change[lo] += 1
                change[n] -= 1
        # Recompute
        change = [0] * n
        for i in range(n):
            lo = (i + 1) % n
            hi = (i - nums[i] + n) % n
            if lo <= hi:
                change[lo] += 1
                if hi + 1 < n:
                    change[hi + 1] -= 1
            else:
                change[0] += 1
                if hi + 1 < n:
                    change[hi + 1] -= 1
                change[lo] += 1
        best = -1
        best_k = 0
        cur = 0
        for k in range(n):
            cur += change[k]
            if cur > best:
                best = cur
                best_k = k
        return best_k
