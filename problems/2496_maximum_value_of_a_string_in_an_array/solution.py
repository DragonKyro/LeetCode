from typing import List


class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        def value(s: str) -> int:
            return int(s) if s.isdigit() else len(s)
        return max(value(s) for s in strs)
