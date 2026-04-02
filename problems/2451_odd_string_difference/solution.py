from typing import List


class Solution:
    def oddString(self, words: List[str]) -> str:
        def diff(word: str) -> tuple:
            return tuple(ord(word[i+1]) - ord(word[i]) for i in range(len(word) - 1))
        diffs = [diff(w) for w in words]
        if diffs[0] == diffs[1]:
            target = diffs[0]
        elif diffs[0] == diffs[2]:
            target = diffs[0]
        else:
            target = diffs[1]
        for i, d in enumerate(diffs):
            if d != target:
                return words[i]
        return ''
