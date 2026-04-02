class Solution:
    def reformat(self, s: str) -> str:
        letters = [c for c in s if c.isalpha()]
        digits = [c for c in s if c.isdigit()]
        if abs(len(letters) - len(digits)) > 1:
            return ''
        if len(digits) > len(letters):
            letters, digits = digits, letters
        res = []
        for i in range(len(digits)):
            res.append(letters[i])
            res.append(digits[i])
        if len(letters) > len(digits):
            res.append(letters[-1])
        return ''.join(res)
