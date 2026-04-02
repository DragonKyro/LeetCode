from typing import List


class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        n = len(nums)
        total = n * (n + 1) // 2
        def atMost(k):
            count = 0
            freq = {}
            l = 0
            for r in range(n):
                freq[nums[r]] = freq.get(nums[r], 0) + 1
                while len(freq) > k:
                    freq[nums[l]] -= 1
                    if freq[nums[l]] == 0:
                        del freq[nums[l]]
                    l += 1
                count += r - l + 1
            return count
        lo, hi = 1, n
        while lo < hi:
            mid = (lo + hi) // 2
            if atMost(mid) >= (total + 1) // 2:
                hi = mid
            else:
                lo = mid + 1
        return lo
