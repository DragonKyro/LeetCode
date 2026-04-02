class Solution:
    def judgePoint24(self, cards: list[int]) -> bool:
        if len(cards) == 1:
            return abs(cards[0] - 24) < 1e-6
        for i in range(len(cards)):
            for j in range(len(cards)):
                if i == j:
                    continue
                rest = [cards[k] for k in range(len(cards)) if k != i and k != j]
                a, b = cards[i], cards[j]
                for val in [a + b, a - b, a * b]:
                    if self.judgePoint24(rest + [val]):
                        return True
                if b != 0:
                    if self.judgePoint24(rest + [a / b]):
                        return True
        return False
