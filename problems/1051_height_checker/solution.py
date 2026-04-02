class Solution:
    def heightChecker(self, heights: list[int]) -> int:
        expected = sorted(heights)
        return sum(h != e for h, e in zip(heights, expected))
