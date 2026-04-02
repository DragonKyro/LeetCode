from typing import List


class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        mapping = collections.defaultdict(list)
        for s in allowed:
            mapping[(s[0], s[1])].append(s[2])
        def solve(bottom, next_row, idx):
            if len(bottom) == 1:
                return True
            if idx == len(bottom) - 1:
                return solve(next_row, '', 0)
            for c in mapping.get((bottom[idx], bottom[idx+1]), []):
                if solve(bottom, next_row + c, idx + 1):
                    return True
            return False
        return solve(bottom, '', 0)
