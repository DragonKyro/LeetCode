from typing import List


class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        from collections import deque
        n = len(deck)
        deck.sort()
        idx = deque(range(n))
        result = [0] * n
        for card in deck:
            result[idx.popleft()] = card
            if idx:
                idx.append(idx.popleft())
        return result
