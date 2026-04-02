class Solution:
    def addMinimum(self, word: str) -> int:
        target = 'abc'
        ans = 0
        i = 0
        j = 0
        while i < len(word):
            if word[i] == target[j]:
                i += 1
            else:
                ans += 1
            j = (j + 1) % 3
        ans += (3 - j) % 3
        return ans
