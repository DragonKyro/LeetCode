from typing import List


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        def backtrack(start, path, remaining):
            if len(path) == k:
                if remaining == 0:
                    res.append(path[:])
                return
            for i in range(start, 10):
                if i > remaining:
                    break
                path.append(i)
                backtrack(i + 1, path, remaining - i)
                path.pop()
        backtrack(1, [], n)
        return res
