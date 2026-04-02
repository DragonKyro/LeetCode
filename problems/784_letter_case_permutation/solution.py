from typing import List


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        result = [[]]
        for c in s:
            if c.isalpha():
                result = [r + [v] for r in result for v in [c.lower(), c.upper()]]
            else:
                result = [r + [c] for r in result]
        return [''.join(r) for r in result]
