from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        nums_str = list(map(str, nums))
        nums_str.sort(key=cmp_to_key(lambda a, b: 1 if a + b < b + a else -1))
        result = ''.join(nums_str)
        return '0' if result[0] == '0' else result
