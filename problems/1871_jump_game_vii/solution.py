class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        if s[-1] == '1':
            return False
        dp = [False] * n
        dp[0] = True
        count = 0
        for i in range(1, n):
            if i >= minJump:
                count += dp[i - minJump]
            if i > maxJump:
                count -= dp[i - maxJump - 1]
            dp[i] = count > 0 and s[i] == '0'
        return dp[-1]
