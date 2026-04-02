class Solution:
    def countAnagrams(self, s: str) -> int:
        MOD = 10**9 + 7
        from math import factorial
        ans = 1
        for word in s.split():
            ans = ans * factorial(len(word)) % MOD
            for c in set(word):
                ans = ans * pow(factorial(word.count(c)), MOD - 2, MOD) % MOD
        return ans
