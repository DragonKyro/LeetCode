from typing import List


class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort()
        n = len(nums1)
        res = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                remaining = [nums1[k] for k in range(n) if k != i and k != j]
                x = nums2[0] - remaining[0]
                if all(remaining[k] + x == nums2[k] for k in range(len(nums2))):
                    res = min(res, x)
        return res
