from typing import List


class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        result = n + 1
        dq = deque()
        for i in range(n + 1):
            while dq and prefix[i] - prefix[dq[0]] >= k:
                result = min(result, i - dq.popleft())
            while dq and prefix[i] <= prefix[dq[-1]]:
                dq.pop()
            dq.append(i)
        return result if result <= n else -1
