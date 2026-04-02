from shared.python.data_structures import TreeNode


class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        self.result = float('inf')
        min_val = root.val
        def dfs(node):
            if not node:
                return
            if min_val < node.val < self.result:
                self.result = node.val
            elif node.val == min_val:
                dfs(node.left)
                dfs(node.right)
        dfs(root)
        return self.result if self.result < float('inf') else -1
