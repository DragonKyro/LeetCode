class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> list[int]:
        s = sorted([a, b, c])
        if s[2] - s[0] == 2:
            return [0, 0]
        min_moves = 1 if s[1] - s[0] <= 2 or s[2] - s[1] <= 2 else 2
        max_moves = s[2] - s[0] - 2
        return [min_moves, max_moves]
