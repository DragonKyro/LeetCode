class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res = balance = 0
        for c in s:
            balance += 1 if c == 'L' else -1
            if balance == 0:
                res += 1
        return res
