from typing import List


class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        elem_sum = sum(nums)
        digit_sum = sum(int(d) for n in nums for d in str(n))
        return abs(elem_sum - digit_sum)
