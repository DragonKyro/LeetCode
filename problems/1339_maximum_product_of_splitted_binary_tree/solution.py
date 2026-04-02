from shared.python.data_structures import TreeNode


class Solution:
    def maxProduct(self, root: 'TreeNode') -> int:
        MOD = 10 ** 9 + 7
        subtree_sums: list[int] = []
        def total_sum(node: 'TreeNode') -> int:
            if not node:
                return 0
            s = node.val + total_sum(node.left) + total_sum(node.right)
            subtree_sums.append(s)
            return s
        total = total_sum(root)
        return max(s * (total - s) for s in subtree_sums) % MOD
