class Solution:
    def stringHash(self, s: str, k: int) -> str:
        res = []
        for i in range(0, len(s), k):
            total = sum(ord(c) - ord('a') for c in s[i:i+k])
            res.append(chr(total % 26 + ord('a')))
        return ''.join(res)
