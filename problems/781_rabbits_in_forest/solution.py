from typing import List


class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        count = collections.Counter(answers)
        result = 0
        for k, v in count.items():
            groups = (v + k) // (k + 1)
            result += groups * (k + 1)
        return result
