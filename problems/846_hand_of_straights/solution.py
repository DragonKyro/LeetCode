from typing import List


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        counts = Counter(hand)
        for card in sorted(counts):
            if counts[card] > 0:
                cnt = counts[card]
                for i in range(groupSize):
                    if counts[card + i] < cnt:
                        return False
                    counts[card + i] -= cnt
        return True
