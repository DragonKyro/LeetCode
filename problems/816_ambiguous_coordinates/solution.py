from typing import List


class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        def make(frag: str) -> List[str]:
            n = len(frag)
            res = []
            for d in range(1, n + 1):
                left = frag[:d]
                right = frag[d:]
                if (left == '0' or not left.startswith('0')) and not right.endswith('0'):
                    res.append(left + ('.' if right else '') + right)
            return res
        s = s[1:-1]
        result = []
        for i in range(1, len(s)):
            for x in make(s[:i]):
                for y in make(s[i:]):
                    result.append(f"({x}, {y})")
        return result
