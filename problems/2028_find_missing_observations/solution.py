class Solution:
    def missingRolls(self, rolls: list[int], mean: int, n: int) -> list[int]:
        total = mean * (len(rolls) + n) - sum(rolls)
        if total < n or total > 6 * n:
            return []
        base = total // n
        remainder = total % n
        result = [base + 1] * remainder + [base] * (n - remainder)
        return result
