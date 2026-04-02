from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.total = 0
        
        def reverse_inorder(node: Optional[TreeNode]) -> None:
            if not node:
                return
            reverse_inorder(node.right)
            self.total += node.val
            node.val = self.total
            reverse_inorder(node.left)
        
        reverse_inorder(root)
        return root
