class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        m = {')':'(', ']':'[', '}':'{'}
        for c in s:
            if c in m:
                if not stack or stack[-1] != m[c]:
                    return False
                stack.pop()
            else:
                stack.append(c)
        return not stack
