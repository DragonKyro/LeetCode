from shared.python.data_structures import TreeNode


class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        left_count = right_count = 0
        def count(node: TreeNode) -> int:
            if not node:
                return 0
            return 1 + count(node.left) + count(node.right)
        def find(node: TreeNode) -> None:
            nonlocal left_count, right_count
            if not node:
                return
            if node.val == x:
                left_count = count(node.left)
                right_count = count(node.right)
                return
            find(node.left)
            find(node.right)
        find(root)
        parent_count = n - left_count - right_count - 1
        return max(left_count, right_count, parent_count) > n // 2
