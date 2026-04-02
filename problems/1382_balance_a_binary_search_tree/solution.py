from shared.python.data_structures import TreeNode


class Solution:
    def balanceBST(self, root: 'TreeNode') -> 'TreeNode':
        nodes: list[int] = []
        def inorder(node: 'TreeNode') -> None:
            if not node:
                return
            inorder(node.left)
            nodes.append(node.val)
            inorder(node.right)
        inorder(root)
        def build(lo: int, hi: int) -> 'TreeNode':
            if lo > hi:
                return None
            mid = (lo + hi) // 2
            node = TreeNode(nodes[mid])
            node.left = build(lo, mid - 1)
            node.right = build(mid + 1, hi)
            return node
        return build(0, len(nodes) - 1)
