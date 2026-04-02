class Solution:
    def deserialize(self, s: str) -> 'NestedInteger':
        if s[0] != '[':
            return NestedInteger(int(s))
        stack = []
        num = ''
        for i, c in enumerate(s):
            if c == '[':
                stack.append(NestedInteger())
            elif c == ']':
                if num:
                    stack[-1].add(NestedInteger(int(num)))
                    num = ''
                if len(stack) > 1:
                    top = stack.pop()
                    stack[-1].add(top)
            elif c == ',':
                if num:
                    stack[-1].add(NestedInteger(int(num)))
                    num = ''
            else:
                num += c
        return stack[0]
