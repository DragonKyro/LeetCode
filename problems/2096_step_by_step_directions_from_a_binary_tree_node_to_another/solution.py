from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def find(node: Optional[TreeNode], target: int, path: list[str]) -> bool:
            if not node:
                return False
            if node.val == target:
                return True
            path.append('L')
            if find(node.left, target, path):
                return True
            path.pop()
            path.append('R')
            if find(node.right, target, path):
                return True
            path.pop()
            return False
        path_start: list[str] = []
        path_dest: list[str] = []
        find(root, startValue, path_start)
        find(root, destValue, path_dest)
        i = 0
        while i < len(path_start) and i < len(path_dest) and path_start[i] == path_dest[i]:
            i += 1
        return 'U' * (len(path_start) - i) + ''.join(path_dest[i:])
