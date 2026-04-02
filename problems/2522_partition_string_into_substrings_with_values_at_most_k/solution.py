class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        parts, cur = 1, 0
        for c in s:
            d = int(c)
            if d > k: return -1
            cur = cur * 10 + d
            if cur > k:
                parts += 1
                cur = d
        return parts
