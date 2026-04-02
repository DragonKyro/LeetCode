from shared.python.data_structures import TreeNode


class Solution:
    def addOneRow(self, root: TreeNode, val: int, depth: int) -> TreeNode:
        if depth == 1:
            new_root = TreeNode(val)
            new_root.left = root
            return new_root
        queue = [root]
        for _ in range(depth - 2):
            queue = [child for node in queue for child in (node.left, node.right) if child]
        for node in queue:
            left = TreeNode(val)
            left.left = node.left
            node.left = left
            right = TreeNode(val)
            right.right = node.right
            node.right = right
        return root
