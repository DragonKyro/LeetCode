from typing import List


class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        return [part for w in words for part in w.split(separator) if part]
