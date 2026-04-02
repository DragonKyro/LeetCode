from typing import List


class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        res = 0
        stack = []
        for x in nums:
            while stack and stack[-1][0] < x:
                stack.pop()
            if stack and stack[-1][0] == x:
                stack[-1] = (x, stack[-1][1] + 1)
                res += stack[-1][1]
            else:
                stack.append((x, 1))
                res += 1
        return res
