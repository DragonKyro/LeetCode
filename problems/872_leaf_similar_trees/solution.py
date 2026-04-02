from typing import List, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def leaves(node: TreeNode) -> List[int]:
            if not node:
                return []
            if not node.left and not node.right:
                return [node.val]
            return leaves(node.left) + leaves(node.right)
        return leaves(root1) == leaves(root2)
