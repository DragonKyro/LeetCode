class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        last_lower = {}
        first_upper = {}
        for i, c in enumerate(word):
            if c.islower():
                last_lower[c] = i
            elif c.isupper() and c not in first_upper:
                first_upper[c] = i
        res = 0
        for c in 'abcdefghijklmnopqrstuvwxyz':
            if c in last_lower and c.upper() in first_upper:
                if last_lower[c] < first_upper[c.upper()]:
                    res += 1
        return res
