from typing import List


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        from collections import Counter
        edge_count = Counter()
        for row in wall:
            pos = 0
            for i in range(len(row) - 1):
                pos += row[i]
                edge_count[pos] += 1
        return len(wall) - (max(edge_count.values()) if edge_count else 0)
