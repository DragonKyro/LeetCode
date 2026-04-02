class Solution:
    def kConcatenationMaxSum(self, arr: list[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        def kadane(a: list[int]) -> int:
            max_sum = 0
            curr = 0
            for x in a:
                curr = max(0, curr + x)
                max_sum = max(max_sum, curr)
            return max_sum
        total = sum(arr)
        if k == 1:
            return kadane(arr) % MOD
        two_max = kadane(arr + arr)
        if total > 0:
            return (two_max + (k - 2) * total) % MOD
        return two_max % MOD
