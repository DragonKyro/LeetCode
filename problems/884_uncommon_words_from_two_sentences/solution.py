from typing import List


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        counts = Counter(s1.split() + s2.split())
        return [w for w, c in counts.items() if c == 1]
