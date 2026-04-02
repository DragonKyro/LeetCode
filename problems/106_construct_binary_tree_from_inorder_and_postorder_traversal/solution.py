from typing import List, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        self.post_idx = len(postorder) - 1
        def helper(left: int, right: int) -> Optional[TreeNode]:
            if left > right:
                return None
            root_val = postorder[self.post_idx]
            self.post_idx -= 1
            root = TreeNode(root_val)
            mid = inorder_map[root_val]
            root.right = helper(mid + 1, right)
            root.left = helper(left, mid - 1)
            return root
        return helper(0, len(inorder) - 1)
