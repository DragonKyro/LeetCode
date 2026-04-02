from typing import Dict, List


class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        seen: Dict[tuple, int] = {}
        while n > 0:
            state = tuple(cells)
            if state in seen:
                n %= seen[state] - n
            seen[state] = n
            if n >= 1:
                n -= 1
                new_cells = [0] * 8
                for i in range(1, 7):
                    new_cells[i] = 1 if cells[i - 1] == cells[i + 1] else 0
                cells = new_cells
        return cells
