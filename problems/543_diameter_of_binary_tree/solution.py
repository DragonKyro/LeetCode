from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        
        def depth(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            left = depth(node.left)
            right = depth(node.right)
            self.ans = max(self.ans, left + right)
            return 1 + max(left, right)
        
        depth(root)
        return self.ans
