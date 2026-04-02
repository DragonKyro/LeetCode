class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0
        sign = 1
        idx = 0
        if s[0] in '+-':
            sign = -1 if s[0] == '-' else 1
            idx = 1
        num = 0
        while idx < len(s) and s[idx].isdigit():
            num = num * 10 + int(s[idx])
            idx += 1
        num *= sign
        return max(-2**31, min(2**31 - 1, num))
