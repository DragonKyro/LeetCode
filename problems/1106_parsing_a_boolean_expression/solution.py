class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        for ch in expression:
            if ch == ',':
                continue
            elif ch == ')':
                seen = []
                while stack[-1] != '(':
                    seen.append(stack.pop())
                stack.pop()  # remove '('
                operator = stack.pop()
                if operator == '!':
                    stack.append(not seen[0])
                elif operator == '&':
                    stack.append(all(seen))
                elif operator == '|':
                    stack.append(any(seen))
            elif ch == 't':
                stack.append(True)
            elif ch == 'f':
                stack.append(False)
            else:
                stack.append(ch)
        return stack[0]
