from typing import List


class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        ans = []
        mx = 0
        s = 0
        for n in nums:
            mx = max(mx, n)
            s += n + mx
            ans.append(s)
        return ans
