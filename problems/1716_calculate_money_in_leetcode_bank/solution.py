class Solution:
    def totalMoney(self, n: int) -> int:
        weeks = n // 7
        days = n % 7
        total = 0
        for w in range(weeks):
            total += 28 + 7 * w
        for d in range(days):
            total += weeks + 1 + d
        return total
