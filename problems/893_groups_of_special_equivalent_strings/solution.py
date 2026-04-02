from typing import List


class Solution:
    def numSpecialEquivGroups(self, words: List[str]) -> int:
        def signature(w: str) -> tuple:
            even = sorted(w[i] for i in range(0, len(w), 2))
            odd = sorted(w[i] for i in range(1, len(w), 2))
            return (tuple(even), tuple(odd))
        return len(set(signature(w) for w in words))
