from typing import List, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return []
        if not root.left and not root.right:
            return [str(root.val)]
        paths = []
        for path in self.binaryTreePaths(root.left):
            paths.append(f"{root.val}->{path}")
        for path in self.binaryTreePaths(root.right):
            paths.append(f"{root.val}->{path}")
        return paths
