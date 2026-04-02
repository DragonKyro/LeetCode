from shared.python.data_structures import TreeNode


class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root or root.val == val:
            return root
        if val < root.val:
            return self.searchBST(root.left, val)
        return self.searchBST(root.right, val)
