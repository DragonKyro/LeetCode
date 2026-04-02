class Solution:
    def findBestValue(self, arr: list[int], target: int) -> int:
        arr.sort()
        n = len(arr)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + arr[i]
        ans = 0
        min_diff = float('inf')
        for value in range(max(arr) + 1):
            import bisect
            idx = bisect.bisect_right(arr, value)
            total = prefix[idx] + value * (n - idx)
            diff = abs(total - target)
            if diff < min_diff:
                min_diff = diff
                ans = value
        return ans
