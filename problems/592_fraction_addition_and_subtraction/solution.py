class Solution:
    def fractionAddition(self, expression: str) -> str:
        import re
        from math import gcd
        tokens = re.findall(r'[+-]?\d+/\d+', expression)
        num, den = 0, 1
        for token in tokens:
            n, d = map(int, token.split('/'))
            num = num * d + n * den
            den *= d
            g = gcd(abs(num), abs(den))
            num //= g
            den //= g
        if den < 0:
            num, den = -num, -den
        return f'{num}/{den}'
