from typing import List


class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2 = set(nums1), set(nums2)
        common = s1 & s2
        if common:
            return min(common)
        a, b = min(nums1), min(nums2)
        return min(a * 10 + b, b * 10 + a)
