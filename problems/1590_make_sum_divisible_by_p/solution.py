from typing import List


class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums) % p
        if total == 0:
            return 0
        prefix = {0: -1}
        cur = 0
        res = len(nums)
        for i, n in enumerate(nums):
            cur = (cur + n) % p
            target = (cur - total) % p
            if target in prefix:
                res = min(res, i - prefix[target])
            prefix[cur] = i
        return res if res < len(nums) else -1
