from shared.python.data_structures import TreeNode


class Solution:
    def printTree(self, root: TreeNode) -> list[list[str]]:
        def height(node):
            if not node:
                return 0
            return 1 + max(height(node.left), height(node.right))
        h = height(root)
        rows = h
        cols = 2**h - 1
        result = [[''] * cols for _ in range(rows)]
        def fill(node, r, lo, hi):
            if not node:
                return
            mid = (lo + hi) // 2
            result[r][mid] = str(node.val)
            fill(node.left, r + 1, lo, mid - 1)
            fill(node.right, r + 1, mid + 1, hi)
        fill(root, 0, 0, cols - 1)
        return result
