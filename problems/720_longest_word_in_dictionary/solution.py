from typing import List


class Solution:
    def longestWord(self, words: List[str]) -> str:
        word_set = set(words)
        ans = ''
        for word in words:
            if len(word) > len(ans) or (len(word) == len(ans) and word < ans):
                if all(word[:k] in word_set for k in range(1, len(word))):
                    ans = word
        return ans
