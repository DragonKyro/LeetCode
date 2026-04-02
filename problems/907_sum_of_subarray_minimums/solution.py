from typing import List


class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(arr)
        stack: List[int] = []
        left = [0] * n
        right = [0] * n
        for i in range(n):
            count = 1
            while stack and stack[-1][0] >= arr[i]:
                count += stack.pop()[1]
            left[i] = count
            stack.append((arr[i], count))
        stack = []
        for i in range(n - 1, -1, -1):
            count = 1
            while stack and stack[-1][0] > arr[i]:
                count += stack.pop()[1]
            right[i] = count
            stack.append((arr[i], count))
        result = 0
        for i in range(n):
            result = (result + arr[i] * left[i] * right[i]) % MOD
        return result
