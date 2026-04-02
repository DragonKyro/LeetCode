from typing import List


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        result = []
        for i in range(n):
            result.append('0' if nums[i][i] == '1' else '1')
        return ''.join(result)
