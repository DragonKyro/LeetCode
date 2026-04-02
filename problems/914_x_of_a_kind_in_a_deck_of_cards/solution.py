from typing import List


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        from math import gcd
        from collections import Counter
        counts = Counter(deck)
        g = 0
        for c in counts.values():
            g = gcd(g, c)
        return g >= 2
