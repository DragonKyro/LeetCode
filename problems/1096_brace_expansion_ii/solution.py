class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        def parse(expr: str, i: int) -> tuple:
            result = set()
            current = {''}
            while i < len(expr):
                if expr[i] == '{':
                    inner, i = parse(expr, i + 1)
                    current = {a + b for a in current for b in inner}
                elif expr[i] == '}':
                    result |= current
                    return result, i + 1
                elif expr[i] == ',':
                    result |= current
                    current = {''}
                    i += 1
                else:
                    j = i
                    while j < len(expr) and expr[j].isalpha():
                        j += 1
                    word = expr[i:j]
                    current = {a + word for a in current}
                    i = j
            result |= current
            return result, i
        result, _ = parse(expression, 0)
        return sorted(result)
