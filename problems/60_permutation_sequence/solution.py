class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        import math
        numbers = list(range(1, n + 1))
        k -= 1
        result = []
        for i in range(n, 0, -1):
            fact = math.factorial(i - 1)
            idx = k // fact
            result.append(str(numbers[idx]))
            numbers.pop(idx)
            k %= fact
        return ''.join(result)
