class Solution:
    def getLucky(self, s: str, k: int) -> int:
        num = ''.join(str(ord(c) - ord('a') + 1) for c in s)
        for _ in range(k):
            num = str(sum(int(d) for d in num))
        return int(num)
