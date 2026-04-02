from typing import List


class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        n = len(reward1)
        diff = sorted(range(n), key=lambda i: reward1[i] - reward2[i], reverse=True)
        ans = 0
        for i in range(n):
            if i < k: ans += reward1[diff[i]]
            else: ans += reward2[diff[i]]
        return ans
