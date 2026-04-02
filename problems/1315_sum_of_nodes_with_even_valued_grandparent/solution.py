from shared.python.data_structures import TreeNode


class Solution:
    def sumEvenGrandparent(self, root: 'TreeNode') -> int:
        def dfs(node: 'TreeNode', parent: int, grandparent: int) -> int:
            if not node:
                return 0
            total = node.val if grandparent % 2 == 0 else 0
            total += dfs(node.left, node.val, parent)
            total += dfs(node.right, node.val, parent)
            return total
        return dfs(root, 1, 1)
