from typing import List


class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = set('aeiou')
        prefix = [0] * (len(words) + 1)
        for i, w in enumerate(words):
            prefix[i + 1] = prefix[i] + (1 if w[0] in vowels and w[-1] in vowels else 0)
        return [prefix[r + 1] - prefix[l] for l, r in queries]
