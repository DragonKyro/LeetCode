class Solution:
    def canMakePaliQueries(self, s: str, queries: list[list[int]]) -> list[bool]:
        n = len(s)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] ^ (1 << (ord(s[i]) - ord('a')))
        result = []
        for left, right, k in queries:
            diff = prefix[right + 1] ^ prefix[left]
            odd_count = bin(diff).count('1')
            result.append(odd_count // 2 <= k)
        return result
