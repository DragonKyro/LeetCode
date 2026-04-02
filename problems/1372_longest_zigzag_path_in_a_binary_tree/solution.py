from shared.python.data_structures import TreeNode


class Solution:
    def longestZigZag(self, root: 'TreeNode') -> int:
        self.res = 0
        def dfs(node: 'TreeNode') -> tuple:
            if not node:
                return (-1, -1)
            ll, lr = dfs(node.left)
            rl, rr = dfs(node.right)
            left = lr + 1
            right = rl + 1
            self.res = max(self.res, left, right)
            return (left, right)
        dfs(root)
        return self.res
