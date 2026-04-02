from typing import List


class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        sorted1 = sorted(nums1)
        sorted2 = sorted(range(len(nums2)), key=lambda i: nums2[i])
        result = [0] * len(nums1)
        lo, hi = 0, len(nums1) - 1
        for i in range(len(sorted2) - 1, -1, -1):
            idx = sorted2[i]
            if sorted1[hi] > nums2[idx]:
                result[idx] = sorted1[hi]
                hi -= 1
            else:
                result[idx] = sorted1[lo]
                lo += 1
        return result
