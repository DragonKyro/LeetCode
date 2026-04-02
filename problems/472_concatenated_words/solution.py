from typing import List


class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        word_set = set(words)

        def canForm(word: str) -> bool:
            dp = [False] * (len(word) + 1)
            dp[0] = True
            for i in range(1, len(word) + 1):
                for j in range(i):
                    if dp[j] and word[j:i] in word_set and word[j:i] != word:
                        dp[i] = True
                        break
            return dp[len(word)]

        return [word for word in words if word and canForm(word)]
