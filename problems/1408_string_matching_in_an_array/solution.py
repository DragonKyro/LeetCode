from typing import List


class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = []
        for i, w in enumerate(words):
            for j, other in enumerate(words):
                if i != j and w in other:
                    res.append(w)
                    break
        return res
