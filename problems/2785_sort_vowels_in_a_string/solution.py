class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        v = sorted([c for c in s if c in vowels])
        res = list(s)
        j = 0
        for i in range(len(s)):
            if s[i] in vowels:
                res[i] = v[j]
                j += 1
        return ''.join(res)
