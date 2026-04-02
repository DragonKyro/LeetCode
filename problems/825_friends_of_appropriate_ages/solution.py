from typing import List


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        count = [0] * 121
        for a in ages:
            count[a] += 1
        prefix = [0] * 121
        for i in range(1, 121):
            prefix[i] = prefix[i - 1] + count[i]
        result = 0
        for age in range(15, 121):
            if count[age] == 0:
                continue
            lo = age // 2 + 7
            result += count[age] * (prefix[age] - prefix[lo]) - count[age]
        return result
