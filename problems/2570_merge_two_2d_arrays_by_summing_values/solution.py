from typing import List


class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        from collections import OrderedDict
        d = {}
        for id, val in nums1:
            d[id] = d.get(id, 0) + val
        for id, val in nums2:
            d[id] = d.get(id, 0) + val
        return sorted(d.items())
