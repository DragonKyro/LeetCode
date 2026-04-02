from typing import List


class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        count = Counter(tasks)
        rounds = 0
        for v in count.values():
            if v == 1:
                return -1
            rounds += (v + 2) // 3
        return rounds
