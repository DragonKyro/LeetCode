class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = set('aeiou')
        count = sum(1 for c in s[:k] if c in vowels)
        res = count
        for i in range(k, len(s)):
            count += (s[i] in vowels) - (s[i - k] in vowels)
            res = max(res, count)
        return res
