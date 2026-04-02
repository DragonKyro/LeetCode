from typing import List


class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        n = len(parent)
        children = defaultdict(list)
        for i in range(1, n):
            children[parent[i]].append(i)
        self.ans = 1
        def dfs(node: int) -> int:
            top1 = top2 = 0
            for child in children[node]:
                length = dfs(child)
                if s[child] != s[node]:
                    if length > top1:
                        top2 = top1
                        top1 = length
                    elif length > top2:
                        top2 = length
            self.ans = max(self.ans, top1 + top2 + 1)
            return top1 + 1
        dfs(0)
        return self.ans
