from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        graph = defaultdict(list)
        def build(node: TreeNode, parent: TreeNode) -> None:
            if not node:
                return
            if parent:
                graph[node.val].append(parent.val)
                graph[parent.val].append(node.val)
            build(node.left, node)
            build(node.right, node)
        build(root, None)
        visited = {start}
        queue = deque([start])
        time = -1
        while queue:
            time += 1
            for _ in range(len(queue)):
                node = queue.popleft()
                for neighbor in graph[node]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
        return time
