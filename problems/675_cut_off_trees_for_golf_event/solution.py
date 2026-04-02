class Solution:
    def cutOffTree(self, forest: list[list[int]]) -> int:
        from collections import deque
        trees = sorted([(forest[i][j], i, j) for i in range(len(forest)) for j in range(len(forest[0])) if forest[i][j] > 1])
        def bfs(sr, sc, tr, tc):
            if sr == tr and sc == tc:
                return 0
            m, n = len(forest), len(forest[0])
            visited = set()
            visited.add((sr, sc))
            queue = deque([(sr, sc, 0)])
            while queue:
                r, c, dist = queue.popleft()
                for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in visited and forest[nr][nc] > 0:
                        if nr == tr and nc == tc:
                            return dist + 1
                        visited.add((nr, nc))
                        queue.append((nr, nc, dist + 1))
            return -1
        sr = sc = 0
        total = 0
        for _, tr, tc in trees:
            steps = bfs(sr, sc, tr, tc)
            if steps == -1:
                return -1
            total += steps
            sr, sc = tr, tc
        return total
