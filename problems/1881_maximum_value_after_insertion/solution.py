class Solution:
    def maxValue(self, n: str, x: int) -> str:
        is_neg = n[0] == '-'
        start = 1 if is_neg else 0
        for i in range(start, len(n)):
            digit = int(n[i])
            if is_neg and digit > x:
                return n[:i] + str(x) + n[i:]
            if not is_neg and digit < x:
                return n[:i] + str(x) + n[i:]
        return n + str(x)
