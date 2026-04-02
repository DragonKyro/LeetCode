class Solution:
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        from collections import Counter
        c1 = Counter(nums1)
        res = []
        for n in nums2:
            if c1[n] > 0:
                res.append(n)
                c1[n] -= 1
        return res
