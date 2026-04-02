class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = [0, 0, 0]
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        if any(c < k for c in cnt):
            return -1
        n = len(s)
        ans = n
        j = 0
        window = [0, 0, 0]
        for i in range(n):
            window[ord(s[i]) - ord('a')] += 1
            while any(cnt[x] - window[x] < k for x in range(3)):
                window[ord(s[j]) - ord('a')] -= 1
                j += 1
            ans = min(ans, n - (i - j + 1))
        return ans
