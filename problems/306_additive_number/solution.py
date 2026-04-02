class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        def check(i, j):
            if num[0] == '0' and i > 1:
                return False
            if num[i] == '0' and j - i > 1:
                return False
            a, b = int(num[:i]), int(num[i:j])
            k = j
            while k < n:
                c = a + b
                s = str(c)
                if not num.startswith(s, k):
                    return False
                k += len(s)
                a, b = b, c
            return k == n
        for i in range(1, n):
            for j in range(i + 1, n):
                if check(i, j):
                    return True
        return False
