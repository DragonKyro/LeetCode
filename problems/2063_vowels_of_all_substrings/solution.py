class Solution:
    def countVowels(self, word: str) -> int:
        n = len(word)
        result = 0
        for i, c in enumerate(word):
            if c in 'aeiou':
                result += (i + 1) * (n - i)
        return result
