from typing import List


class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        index = {x: i for i, x in enumerate(arr)}
        dp = defaultdict(lambda: 2)
        result = 0
        for k in range(len(arr)):
            for j in range(k):
                i_val = arr[k] - arr[j]
                if i_val < arr[j] and i_val in index:
                    dp[j, k] = dp[index[i_val], j] + 1
                    result = max(result, dp[j, k])
        return result if result >= 3 else 0
