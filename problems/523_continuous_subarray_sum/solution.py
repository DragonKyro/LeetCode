from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        prefix_mod = {0: -1}
        running = 0
        for i, num in enumerate(nums):
            running += num
            mod = running % k
            if mod in prefix_mod:
                if i - prefix_mod[mod] >= 2:
                    return True
            else:
                prefix_mod[mod] = i
        return False
