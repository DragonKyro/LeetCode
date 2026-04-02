class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:
            s = s.lower()
            at = s.index('@')
            return s[0] + '*****' + s[at - 1:]
        digits = [c for c in s if c.isdigit()]
        local = '***-***-' + ''.join(digits[-4:])
        if len(digits) == 10:
            return local
        return '+' + '*' * (len(digits) - 10) + '-' + local
