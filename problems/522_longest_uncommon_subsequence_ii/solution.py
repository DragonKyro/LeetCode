from typing import List


class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def is_subseq(s: str, t: str) -> bool:
            it = iter(t)
            return all(c in it for c in s)
        
        strs.sort(key=len, reverse=True)
        for i, s in enumerate(strs):
            if all(not is_subseq(s, strs[j]) for j in range(len(strs)) if i != j):
                return len(s)
        return -1
