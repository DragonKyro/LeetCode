class Solution:
    def makeArrayIncreasing(self, arr1: list[int], arr2: list[int]) -> int:
        arr2.sort()
        from bisect import bisect_right
        dp = {-1: 0}
        for num in arr1:
            new_dp = {}
            for prev, ops in dp.items():
                if num > prev:
                    if num not in new_dp or new_dp[num] > ops:
                        new_dp[num] = ops
                idx = bisect_right(arr2, prev)
                if idx < len(arr2):
                    val = arr2[idx]
                    if val not in new_dp or new_dp[val] > ops + 1:
                        new_dp[val] = ops + 1
            dp = new_dp
        if not dp:
            return -1
        return min(dp.values())
