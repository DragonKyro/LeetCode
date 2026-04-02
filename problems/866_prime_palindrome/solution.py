class Solution:
    def primePalindrome(self, n: int) -> int:
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            if x < 4:
                return True
            if x % 2 == 0 or x % 3 == 0:
                return False
            i = 5
            while i * i <= x:
                if x % i == 0 or x % (i + 2) == 0:
                    return False
                i += 6
            return True
        if 8 <= n <= 11:
            return 11
        for length in range(1, 6):
            for root in range(10**(length - 1), 10**length):
                s = str(root)
                pal = int(s + s[-2::-1])
                if pal >= n and is_prime(pal):
                    return pal
        return -1
