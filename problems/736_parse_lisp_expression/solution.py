class Solution:
    def evaluate(self, expression: str) -> int:
        def parse(expr, scope):
            if expr[0] != '(':
                if expr[0] == '-' or expr[0].isdigit():
                    return int(expr)
                for s in reversed(scope):
                    if expr in s:
                        return s[expr]
                return 0
            inner = expr[1:-1]
            tokens = tokenize(inner)
            if tokens[0] == 'let':
                new_scope = scope + [{}]
                i = 1
                while i < len(tokens) - 1:
                    var = tokens[i]
                    val = parse(tokens[i + 1], new_scope)
                    new_scope[-1][var] = val
                    i += 2
                return parse(tokens[-1], new_scope)
            elif tokens[0] == 'add':
                return parse(tokens[1], scope) + parse(tokens[2], scope)
            elif tokens[0] == 'mult':
                return parse(tokens[1], scope) * parse(tokens[2], scope)
            return 0

        def tokenize(s):
            tokens = []
            i = 0
            while i < len(s):
                if s[i] == ' ':
                    i += 1
                elif s[i] == '(':
                    depth = 1
                    j = i + 1
                    while depth > 0:
                        if s[j] == '(': depth += 1
                        elif s[j] == ')': depth -= 1
                        j += 1
                    tokens.append(s[i:j])
                    i = j
                else:
                    j = i
                    while j < len(s) and s[j] != ' ':
                        j += 1
                    tokens.append(s[i:j])
                    i = j
            return tokens

        return parse(expression, [{}])
