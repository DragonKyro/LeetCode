class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set('aeiouAEIOU')
        n = len(s)
        a = sum(1 for c in s[:n // 2] if c in vowels)
        b = sum(1 for c in s[n // 2:] if c in vowels)
        return a == b
