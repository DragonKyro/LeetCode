from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        from collections import deque
        q = deque([root])
        root.val = 0
        while q:
            level_sum = 0
            nodes = []
            for _ in range(len(q)):
                node = q.popleft()
                nodes.append(node)
                if node.left:
                    level_sum += node.left.val
                    q.append(node.left)
                if node.right:
                    level_sum += node.right.val
                    q.append(node.right)
            for node in nodes:
                sibling_sum = (node.left.val if node.left else 0) + (node.right.val if node.right else 0)
                if node.left: node.left.val = level_sum - sibling_sum
                if node.right: node.right.val = level_sum - sibling_sum
        return root
