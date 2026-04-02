class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def val(word: str) -> int:
            return int(''.join(str(ord(c) - ord('a')) for c in word))
        return val(firstWord) + val(secondWord) == val(targetWord)
