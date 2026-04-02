from typing import List


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k == 0:
            return 0 if nums1 == nums2 else -1
        pos = neg = 0
        for a, b in zip(nums1, nums2):
            diff = a - b
            if diff % k != 0: return -1
            if diff > 0: pos += diff // k
            else: neg += (-diff) // k
        return pos if pos == neg else -1
