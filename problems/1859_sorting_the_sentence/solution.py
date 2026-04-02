class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()
        result = [''] * len(words)
        for w in words:
            idx = int(w[-1]) - 1
            result[idx] = w[:-1]
        return ' '.join(result)
