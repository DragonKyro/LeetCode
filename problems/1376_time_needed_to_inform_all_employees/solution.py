class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: list[int], informTime: list[int]) -> int:
        from collections import defaultdict
        children: dict[int, list[int]] = defaultdict(list)
        for i in range(n):
            if manager[i] != -1:
                children[manager[i]].append(i)
        def dfs(node: int) -> int:
            max_time = 0
            for child in children[node]:
                max_time = max(max_time, dfs(child))
            return informTime[node] + max_time
        return dfs(headID)
