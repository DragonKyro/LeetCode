class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        res = []
        def calc(s):
            left = right = 0
            for c in s:
                if c == '(':
                    left += 1
                elif c == ')':
                    if left > 0:
                        left -= 1
                    else:
                        right += 1
            return left, right
        def dfs(s, start, left, right):
            if left == 0 and right == 0:
                if calc(s) == (0, 0):
                    res.append(s)
                return
            for i in range(start, len(s)):
                if i > start and s[i] == s[i - 1]:
                    continue
                if s[i] == ')' and right > 0:
                    dfs(s[:i] + s[i+1:], i, left, right - 1)
                elif s[i] == '(' and left > 0:
                    dfs(s[:i] + s[i+1:], i, left - 1, right)
        left, right = calc(s)
        dfs(s, 0, left, right)
        return res
