from typing import List


class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        window = sum(cardPoints[:n - k])
        min_window = window
        for i in range(n - k, n):
            window += cardPoints[i] - cardPoints[i - (n - k)]
            min_window = min(min_window, window)
        return sum(cardPoints) - min_window
