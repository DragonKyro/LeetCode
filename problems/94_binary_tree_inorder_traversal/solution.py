from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
        result: list[int] = []
        stack: list[TreeNode] = []
        curr = root
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            result.append(curr.val)
            curr = curr.right
        return result
