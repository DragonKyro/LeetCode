from typing import List


class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        parent = list(range(26))

        def find(x: int) -> int:
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        for eq in equations:
            if eq[1] == '=':
                parent[find(ord(eq[0]) - ord('a'))] = find(ord(eq[3]) - ord('a'))
        for eq in equations:
            if eq[1] == '!':
                if find(ord(eq[0]) - ord('a')) == find(ord(eq[3]) - ord('a')):
                    return False
        return True
