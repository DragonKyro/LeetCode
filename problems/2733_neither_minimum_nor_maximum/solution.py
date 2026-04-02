from typing import List


class Solution:
    def neitherMinNorMax(self, nums: List[int]) -> int:
        if len(nums) < 3: return -1
        a = sorted(nums[:3])
        return a[1]
