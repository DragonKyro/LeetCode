from typing import List


class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        from collections import defaultdict
        groups = defaultdict(list)
        for i, n in enumerate(nums):
            groups[n].append(i)
        ans = [0] * len(nums)
        for indices in groups.values():
            m = len(indices)
            prefix = [0] * (m + 1)
            for i in range(m):
                prefix[i+1] = prefix[i] + indices[i]
            for i in range(m):
                left = indices[i] * i - prefix[i]
                right = (prefix[m] - prefix[i+1]) - indices[i] * (m - i - 1)
                ans[indices[i]] = left + right
        return ans
