from typing import List


class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        import bisect
        MOD = 10**9 + 7
        sorted1 = sorted(nums1)
        n = len(nums1)
        total = sum(abs(a - b) for a, b in zip(nums1, nums2))
        max_improve = 0
        for i in range(n):
            curr_diff = abs(nums1[i] - nums2[i])
            idx = bisect.bisect_left(sorted1, nums2[i])
            if idx < n:
                max_improve = max(max_improve, curr_diff - abs(sorted1[idx] - nums2[i]))
            if idx > 0:
                max_improve = max(max_improve, curr_diff - abs(sorted1[idx - 1] - nums2[i]))
        return (total - max_improve) % MOD
