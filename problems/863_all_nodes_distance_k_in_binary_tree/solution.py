from typing import List
from shared.python.data_structures import TreeNode


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parent = {}
        def dfs(node: TreeNode, par: TreeNode):
            if node:
                parent[node] = par
                dfs(node.left, node)
                dfs(node.right, node)
        dfs(root, None)
        queue = deque([target])
        visited = {target}
        dist = 0
        while queue:
            if dist == k:
                return [node.val for node in queue]
            for _ in range(len(queue)):
                node = queue.popleft()
                for nei in [node.left, node.right, parent[node]]:
                    if nei and nei not in visited:
                        visited.add(nei)
                        queue.append(nei)
            dist += 1
        return []
