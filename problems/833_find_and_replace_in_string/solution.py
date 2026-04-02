from typing import List


class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        lookup = {}
        for i, (idx, src, tgt) in enumerate(zip(indices, sources, targets)):
            if s[idx:idx + len(src)] == src:
                lookup[idx] = (len(src), tgt)
        result = []
        i = 0
        while i < len(s):
            if i in lookup:
                result.append(lookup[i][1])
                i += lookup[i][0]
            else:
                result.append(s[i])
                i += 1
        return ''.join(result)
