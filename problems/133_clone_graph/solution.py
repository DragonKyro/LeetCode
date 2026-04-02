from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        cloned = {}
        def dfs(n: 'Node') -> 'Node':
            if n in cloned:
                return cloned[n]
            copy = Node(n.val)
            cloned[n] = copy
            for neighbor in n.neighbors:
                copy.neighbors.append(dfs(neighbor))
            return copy
        return dfs(node)
