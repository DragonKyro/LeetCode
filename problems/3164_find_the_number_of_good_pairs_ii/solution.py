from typing import List


class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        from collections import Counter
        cnt2 = Counter(b * k for b in nums2)
        res = 0
        for a in nums1:
            d = 1
            while d * d <= a:
                if a % d == 0:
                    if d in cnt2:
                        res += cnt2[d]
                    if d != a // d and (a // d) in cnt2:
                        res += cnt2[a // d]
                d += 1
        return res
