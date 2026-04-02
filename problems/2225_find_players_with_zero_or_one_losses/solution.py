from typing import List


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losses = Counter()
        players = set()
        for w, l in matches:
            players.add(w)
            players.add(l)
            losses[l] += 1
        no_loss = sorted(p for p in players if losses[p] == 0)
        one_loss = sorted(p for p in players if losses[p] == 1)
        return [no_loss, one_loss]
