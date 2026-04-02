from typing import List


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        last_seen = {}
        result = float('inf')
        for i, card in enumerate(cards):
            if card in last_seen:
                result = min(result, i - last_seen[card] + 1)
            last_seen[card] = i
        return result if result != float('inf') else -1
