from shared.python.data_structures import TreeNode


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node: TreeNode, max_val: int) -> int:
            if not node:
                return 0
            count = 1 if node.val >= max_val else 0
            new_max = max(max_val, node.val)
            return count + dfs(node.left, new_max) + dfs(node.right, new_max)
        return dfs(root, root.val)
