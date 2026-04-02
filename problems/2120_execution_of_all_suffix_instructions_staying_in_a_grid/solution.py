class Solution:
    def executeInstructions(self, n: int, startPos: list[int], s: str) -> list[int]:
        result: list[int] = []
        moves = {'L': (0, -1), 'R': (0, 1), 'U': (-1, 0), 'D': (1, 0)}
        for i in range(len(s)):
            r, c = startPos
            count = 0
            for j in range(i, len(s)):
                dr, dc = moves[s[j]]
                r += dr
                c += dc
                if 0 <= r < n and 0 <= c < n:
                    count += 1
                else:
                    break
            result.append(count)
        return result
