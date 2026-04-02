class Solution:
    def isEscapePossible(self, blocked: list[list[int]], source: list[int], target: list[int]) -> bool:
        blocked_set = set(map(tuple, blocked))
        limit = len(blocked) * (len(blocked) - 1) // 2

        def bfs(start: list[int], end: list[int]) -> bool:
            queue = collections.deque([tuple(start)])
            visited = {tuple(start)}
            while queue:
                if len(visited) > limit:
                    return True
                r, c = queue.popleft()
                if [r, c] == end:
                    return True
                for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < 10**6 and 0 <= nc < 10**6 and (nr,nc) not in blocked_set and (nr,nc) not in visited:
                        visited.add((nr,nc))
                        queue.append((nr,nc))
            return False

        return bfs(source, target) and bfs(target, source)
