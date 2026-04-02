from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        from collections import defaultdict
        count = defaultdict(int)
        count[0] = 1
        result = 0
        prefix = 0
        for num in nums:
            prefix += num
            result += count[prefix - k]
            count[prefix] += 1
        return result
