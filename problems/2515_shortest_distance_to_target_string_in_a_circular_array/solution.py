from typing import List


class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        ans = n
        for i in range(n):
            if words[i] == target:
                ans = min(ans, min(abs(i - startIndex), n - abs(i - startIndex)))
        return ans if ans < n else -1
