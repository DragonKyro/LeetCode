from typing import List


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        def is_subseq(w: str) -> bool:
            it = iter(s)
            return all(c in it for c in w)
        
        dictionary.sort(key=lambda x: (-len(x), x))
        for word in dictionary:
            if is_subseq(word):
                return word
        return ''
