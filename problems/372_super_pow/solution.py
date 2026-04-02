class Solution:
    def superPow(self, a: int, b: list[int]) -> int:
        MOD = 1337
        def powmod(base, exp):
            base %= MOD
            result = 1
            while exp > 0:
                if exp & 1:
                    result = result * base % MOD
                base = base * base % MOD
                exp >>= 1
            return result
        result = 1
        for digit in b:
            result = powmod(result, 10) * powmod(a, digit) % MOD
        return result
