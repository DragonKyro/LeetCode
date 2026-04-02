class Solution:
    def numWays(self, s: str) -> int:
        MOD = 10 ** 9 + 7
        ones = s.count('1')
        if ones % 3 != 0:
            return 0
        if ones == 0:
            n = len(s)
            return (n - 1) * (n - 2) // 2 % MOD
        target = ones // 3
        count = 0
        ways1 = ways2 = 0
        for c in s:
            if c == '1':
                count += 1
            if count == target:
                ways1 += 1
            if count == 2 * target:
                ways2 += 1
        return ways1 * ways2 % MOD
