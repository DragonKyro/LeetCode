class Solution:
    def fallingSquares(self, positions: list[list[int]]) -> list[int]:
        intervals = []
        result = []
        max_height = 0
        for left, side in positions:
            right = left + side
            height = side
            for l, r, h in intervals:
                if l < right and left < r:
                    height = max(height, h + side)
            intervals.append((left, right, height))
            max_height = max(max_height, height)
            result.append(max_height)
        return result
