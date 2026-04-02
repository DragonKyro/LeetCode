from shared.python.data_structures import TreeNode


class Solution:
    def bstFromPreorder(self, preorder: list[int]) -> TreeNode:
        self.idx = 0
        def build(bound: int) -> TreeNode:
            if self.idx >= len(preorder) or preorder[self.idx] > bound:
                return None
            val = preorder[self.idx]
            self.idx += 1
            node = TreeNode(val)
            node.left = build(val)
            node.right = build(bound)
            return node
        return build(float('inf'))
