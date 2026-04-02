class Solution:
    def gridIllumination(self, n: int, lamps: list[list[int]], queries: list[list[int]]) -> list[int]:
        rows = collections.Counter()
        cols = collections.Counter()
        diag1 = collections.Counter()
        diag2 = collections.Counter()
        lamp_set = set()
        for r, c in lamps:
            if (r, c) not in lamp_set:
                lamp_set.add((r, c))
                rows[r] += 1
                cols[c] += 1
                diag1[r - c] += 1
                diag2[r + c] += 1
        ans = []
        for r, c in queries:
            if rows[r] > 0 or cols[c] > 0 or diag1[r - c] > 0 or diag2[r + c] > 0:
                ans.append(1)
            else:
                ans.append(0)
            for dr in range(-1, 2):
                for dc in range(-1, 2):
                    nr, nc = r + dr, c + dc
                    if (nr, nc) in lamp_set:
                        lamp_set.remove((nr, nc))
                        rows[nr] -= 1
                        cols[nc] -= 1
                        diag1[nr - nc] -= 1
                        diag2[nr + nc] -= 1
        return ans
