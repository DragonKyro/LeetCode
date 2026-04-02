class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        digits = [int(d) for d in str(n + 1)]
        k = len(digits)
        count = 0
        for i in range(1, k):
            count += 9 * self.perm(9, i - 1)
        seen = set()
        for i, d in enumerate(digits):
            for x in range(0 if i else 1, d):
                if x not in seen:
                    count += self.perm(9 - i, k - i - 1)
            if d in seen:
                break
            seen.add(d)
        return n - count

    def perm(self, n: int, k: int) -> int:
        result = 1
        for i in range(k):
            result *= (n - i)
        return result
