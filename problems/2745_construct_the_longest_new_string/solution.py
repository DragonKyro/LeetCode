class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        return (min(x, y) * 2 + (1 if x != y else 0) + z) * 2
