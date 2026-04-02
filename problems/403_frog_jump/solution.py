from typing import List


class Solution:
    def canCross(self, stones: List[int]) -> bool:
        stone_set = {s: set() for s in stones}
        stone_set[0].add(0)
        for stone in stones:
            for k in stone_set[stone]:
                for step in [k - 1, k, k + 1]:
                    if step > 0 and stone + step in stone_set:
                        stone_set[stone + step].add(step)
        return len(stone_set[stones[-1]]) > 0
