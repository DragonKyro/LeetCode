class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        from collections import Counter
        count = Counter(tiles)
        def backtrack() -> int:
            total = 0
            for c in count:
                if count[c] > 0:
                    count[c] -= 1
                    total += 1 + backtrack()
                    count[c] += 1
            return total
        return backtrack()
