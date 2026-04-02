from typing import List


class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        from collections import defaultdict
        cnt = defaultdict(int)
        pairs = 0
        ans = 0
        j = 0
        for i in range(len(nums)):
            pairs += cnt[nums[i]]
            cnt[nums[i]] += 1
            while pairs >= k:
                cnt[nums[j]] -= 1
                pairs -= cnt[nums[j]]
                j += 1
            ans += j
        return ans
