from typing import List


class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        from math import gcd
        count = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                first = int(str(nums[i])[0])
                last = nums[j] % 10
                if gcd(first, last) == 1:
                    count += 1
        return count
