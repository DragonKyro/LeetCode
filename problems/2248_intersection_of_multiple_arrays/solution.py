from typing import List


class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        count = Counter()
        for arr in nums:
            for x in arr:
                count[x] += 1
        return sorted(x for x in count if count[x] == len(nums))
