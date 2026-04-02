from typing import List


class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match(word: str) -> bool:
            m1, m2 = {}, {}
            for w, p in zip(word, pattern):
                if m1.get(w, p) != p or m2.get(p, w) != w:
                    return False
                m1[w] = p
                m2[p] = w
            return True
        return [w for w in words if match(w)]
