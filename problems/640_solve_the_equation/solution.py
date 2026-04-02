class Solution:
    def solveEquation(self, equation: str) -> str:
        import re
        def parse(expr):
            coef = val = 0
            tokens = re.findall(r'[+-]?[^+-]+', expr)
            for token in tokens:
                token = token.strip()
                if 'x' in token:
                    t = token.replace('x', '')
                    if t in ('', '+'): coef += 1
                    elif t == '-': coef -= 1
                    else: coef += int(t)
                else:
                    val += int(token)
            return coef, val
        left, right = equation.split('=')
        lc, lv = parse(left)
        rc, rv = parse(right)
        coef = lc - rc
        val = rv - lv
        if coef == 0:
            return 'Infinite solutions' if val == 0 else 'No solution'
        return 'x=' + str(val // coef)
