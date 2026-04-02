from typing import List


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        count = {0: 1}
        prefix = 0
        result = 0
        for num in nums:
            prefix = (prefix + num) % k
            result += count.get(prefix, 0)
            count[prefix] = count.get(prefix, 0) + 1
        return result
