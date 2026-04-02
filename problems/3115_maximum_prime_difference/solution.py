from typing import List


class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        def is_prime(n):
            if n < 2: return False
            if n < 4: return True
            if n % 2 == 0 or n % 3 == 0: return False
            i = 5
            while i * i <= n:
                if n % i == 0 or n % (i + 2) == 0: return False
                i += 6
            return True
        first = last = -1
        for i, x in enumerate(nums):
            if is_prime(x):
                if first == -1: first = i
                last = i
        return last - first
