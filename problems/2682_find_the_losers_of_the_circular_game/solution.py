from typing import List


class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        visited = [False] * n
        cur = 0
        step = 1
        while not visited[cur]:
            visited[cur] = True
            cur = (cur + step * k) % n
            step += 1
        return [i + 1 for i in range(n) if not visited[i]]
