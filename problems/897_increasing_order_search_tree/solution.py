from shared.python.data_structures import TreeNode


class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummy = TreeNode(0)
        self.curr = dummy
        def inorder(node: TreeNode):
            if not node:
                return
            inorder(node.left)
            node.left = None
            self.curr.right = node
            self.curr = node
            inorder(node.right)
        inorder(root)
        return dummy.right
