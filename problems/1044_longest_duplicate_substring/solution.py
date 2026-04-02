class Solution:
    def longestDupSubstring(self, s: str) -> str:
        def check(length: int) -> str:
            MOD = (1 << 61) - 1
            base = 26
            h = 0
            power = pow(base, length, MOD)
            seen = {}
            for i in range(len(s)):
                h = (h * base + ord(s[i]) - ord('a')) % MOD
                if i >= length:
                    h = (h - (ord(s[i - length]) - ord('a')) * power) % MOD
                if i >= length - 1:
                    if h in seen:
                        for j in seen[h]:
                            if s[j:j+length] == s[i-length+1:i+1]:
                                return s[j:j+length]
                        seen[h].append(i - length + 1)
                    else:
                        seen[h] = [i - length + 1]
            return ""
        lo, hi = 0, len(s) - 1
        result = ""
        while lo <= hi:
            mid = (lo + hi) // 2
            dup = check(mid)
            if dup:
                result = dup
                lo = mid + 1
            else:
                hi = mid - 1
        return result
