from typing import List


class Solution:
    def basicCalculatorIV(self, expression: str, evalvars: List[str], evalints: List[int]) -> List[str]:
        from collections import Counter
        lookup = dict(zip(evalvars, evalints))

        def combine(left, right, op):
            if op == '+':
                result = Counter(left)
                for k, v in right.items():
                    result[k] += v
                return result
            elif op == '-':
                result = Counter(left)
                for k, v in right.items():
                    result[k] -= v
                return result
            else:
                result = Counter()
                for k1, v1 in left.items():
                    for k2, v2 in right.items():
                        terms = tuple(sorted(k1 + k2))
                        result[terms] += v1 * v2
                return result

        def parse(tokens, i):
            result, op = Counter(), '+'
            while i < len(tokens) and tokens[i] != ')':
                if tokens[i] in '+-':
                    op = tokens[i]
                    i += 1
                elif tokens[i] == '*':
                    op = '*'
                    i += 1
                elif tokens[i] == '(':
                    inner, i = parse(tokens, i + 1)
                    i += 1
                    result = combine(result, inner, op) if op != '*' else combine(result, inner, op)
                else:
                    token = tokens[i]
                    i += 1
                    if token in lookup:
                        term = Counter({(): lookup[token]})
                    elif token.lstrip('-').isdigit():
                        term = Counter({(): int(token)})
                    else:
                        term = Counter({(token,): 1})
                    if op == '*':
                        result = combine(result, term, '*')
                    else:
                        result = combine(result, term, op)
            return result, i

        tokens = []
        i = 0
        while i < len(expression):
            if expression[i] == ' ':
                i += 1
            elif expression[i] in '()*+-':
                tokens.append(expression[i])
                i += 1
            else:
                j = i
                while j < len(expression) and expression[j] not in ' ()*+-':
                    j += 1
                tokens.append(expression[i:j])
                i = j

        def do_parse(tokens):
            def parse_expr(idx):
                left, idx = parse_term(idx)
                while idx < len(tokens) and tokens[idx] in '+-':
                    op = tokens[idx]
                    idx += 1
                    right, idx = parse_term(idx)
                    left = combine(left, right, op)
                return left, idx

            def parse_term(idx):
                left, idx = parse_factor(idx)
                while idx < len(tokens) and tokens[idx] == '*':
                    idx += 1
                    right, idx = parse_factor(idx)
                    left = combine(left, right, '*')
                return left, idx

            def parse_factor(idx):
                if tokens[idx] == '(':
                    idx += 1
                    result, idx = parse_expr(idx)
                    idx += 1
                    return result, idx
                token = tokens[idx]
                idx += 1
                if token in lookup:
                    return Counter({(): lookup[token]}), idx
                elif token.lstrip('-').isdigit():
                    return Counter({(): int(token)}), idx
                else:
                    return Counter({(token,): 1}), idx

            result, _ = parse_expr(0)
            return result

        poly = do_parse(tokens)
        terms = [(k, v) for k, v in poly.items() if v != 0]
        terms.sort(key=lambda x: (-len(x[0]), x[0]))
        result = []
        for k, v in terms:
            if k:
                result.append(str(v) + '*' + '*'.join(k))
            else:
                result.append(str(v))
        return result
