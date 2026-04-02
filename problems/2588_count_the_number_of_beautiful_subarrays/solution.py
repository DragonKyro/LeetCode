from typing import List


class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        from collections import defaultdict
        cnt = defaultdict(int)
        cnt[0] = 1
        xor_sum = 0
        ans = 0
        for n in nums:
            xor_sum ^= n
            ans += cnt[xor_sum]
            cnt[xor_sum] += 1
        return ans
