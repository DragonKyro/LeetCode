class Solution:
    def punishmentNumber(self, n: int) -> int:
        def canPartition(s: str, target: int) -> bool:
            if not s:
                return target == 0
            for i in range(1, len(s) + 1):
                if int(s[:i]) <= target and canPartition(s[i:], target - int(s[:i])):
                    return True
            return False
        ans = 0
        for i in range(1, n + 1):
            sq = i * i
            if canPartition(str(sq), i):
                ans += sq
        return ans
