from typing import Dict, List


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        count: Dict[int, int] = {0: 1}
        prefix = 0
        result = 0
        for num in nums:
            prefix += num
            result += count.get(prefix - goal, 0)
            count[prefix] = count.get(prefix, 0) + 1
        return result
