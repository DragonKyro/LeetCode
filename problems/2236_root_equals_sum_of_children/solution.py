from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def checkTree(self, root: Optional[TreeNode]) -> bool:
        return root.val == root.left.val + root.right.val
