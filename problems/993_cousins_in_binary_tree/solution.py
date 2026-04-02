from typing import Dict, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        from collections import deque
        queue = deque([(root, None, 0)])
        info: Dict[int, tuple] = {}
        while queue:
            node, parent, depth = queue.popleft()
            if node.val == x or node.val == y:
                info[node.val] = (parent, depth)
            if len(info) == 2:
                break
            if node.left:
                queue.append((node.left, node, depth + 1))
            if node.right:
                queue.append((node.right, node, depth + 1))
        return info[x][1] == info[y][1] and info[x][0] != info[y][0]
