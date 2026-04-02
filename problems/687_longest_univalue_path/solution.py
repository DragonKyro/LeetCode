from shared.python.data_structures import TreeNode


class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        self.result = 0
        def dfs(node):
            if not node:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            left_path = left + 1 if node.left and node.left.val == node.val else 0
            right_path = right + 1 if node.right and node.right.val == node.val else 0
            self.result = max(self.result, left_path + right_path)
            return max(left_path, right_path)
        dfs(root)
        return self.result
