from typing import List


class Solution:
    def containVirus(self, isInfected: List[List[int]]) -> int:
        m, n = len(isInfected), len(isInfected[0])
        walls = 0
        while True:
            visited = [[False]*n for _ in range(m)]
            regions = []
            frontiers = []
            perimeters = []
            for i in range(m):
                for j in range(n):
                    if isInfected[i][j] == 1 and not visited[i][j]:
                        region = set()
                        frontier = set()
                        perim = [0]
                        queue = [(i, j)]
                        visited[i][j] = True
                        while queue:
                            r, c = queue.pop()
                            region.add((r, c))
                            for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
                                nr, nc = r+dr, c+dc
                                if 0 <= nr < m and 0 <= nc < n:
                                    if isInfected[nr][nc] == 0:
                                        frontier.add((nr, nc))
                                        perim[0] += 1
                                    elif isInfected[nr][nc] == 1 and not visited[nr][nc]:
                                        visited[nr][nc] = True
                                        queue.append((nr, nc))
                        regions.append(region)
                        frontiers.append(frontier)
                        perimeters.append(perim[0])
            if not regions:
                break
            idx = max(range(len(frontiers)), key=lambda i: len(frontiers[i]))
            walls += perimeters[idx]
            for r, c in regions[idx]:
                isInfected[r][c] = -1
            for i in range(len(regions)):
                if i == idx:
                    continue
                for r, c in frontiers[i]:
                    isInfected[r][c] = 1
            if all(len(f) == 0 for f in frontiers):
                break
        return walls
