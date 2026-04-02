class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s_list = list(s)
        stack: list[int] = []
        for i, c in enumerate(s_list):
            if c == '(':
                stack.append(i)
            elif c == ')':
                if stack:
                    stack.pop()
                else:
                    s_list[i] = ''
        for i in stack:
            s_list[i] = ''
        return ''.join(s_list)
