from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left_h = right_h = 0
        l, r = root, root
        while l:
            left_h += 1
            l = l.left
        while r:
            right_h += 1
            r = r.right
        if left_h == right_h:
            return (1 << left_h) - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
