from typing import List


class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1:
            return 'Flush'
        count = Counter(ranks)
        mx = max(count.values())
        if mx >= 3: return 'Three of a Kind'
        if mx == 2: return 'Pair'
        return 'High Card'
