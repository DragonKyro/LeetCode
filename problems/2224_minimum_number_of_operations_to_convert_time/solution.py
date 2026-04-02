class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        def toMinutes(t: str) -> int:
            h, m = map(int, t.split(':'))
            return h * 60 + m
        diff = toMinutes(correct) - toMinutes(current)
        ops = 0
        for d in [60, 15, 5, 1]:
            ops += diff // d
            diff %= d
        return ops
