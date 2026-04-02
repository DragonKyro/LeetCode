from typing import List


class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        cnt = [0] * 101
        ans = []
        for i in range(len(nums)):
            cnt[nums[i] + 50] += 1
            if i >= k:
                cnt[nums[i - k] + 50] -= 1
            if i >= k - 1:
                count = 0
                for j in range(101):
                    count += cnt[j]
                    if count >= x:
                        ans.append(j - 50 if j - 50 < 0 else 0)
                        break
        return ans
