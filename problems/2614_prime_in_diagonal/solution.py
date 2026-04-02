from typing import List


class Solution:
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        def is_prime(n):
            if n < 2: return False
            if n < 4: return True
            if n % 2 == 0 or n % 3 == 0: return False
            i = 5
            while i * i <= n:
                if n % i == 0 or n % (i+2) == 0: return False
                i += 6
            return True
        n = len(nums)
        ans = 0
        for i in range(n):
            if is_prime(nums[i][i]): ans = max(ans, nums[i][i])
            if is_prime(nums[i][n-1-i]): ans = max(ans, nums[i][n-1-i])
        return ans
