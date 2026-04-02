class Solution:
    def thousandSeparator(self, n: int) -> str:
        s = str(n)
        res = []
        for i, c in enumerate(reversed(s)):
            if i > 0 and i % 3 == 0:
                res.append('.')
            res.append(c)
        return ''.join(reversed(res))
