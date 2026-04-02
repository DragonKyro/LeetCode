from shared.python.data_structures import TreeNode


class Solution:
    def getAllElements(self, root1: 'TreeNode', root2: 'TreeNode') -> list[int]:
        def inorder(node: 'TreeNode', res: list[int]) -> None:
            if not node:
                return
            inorder(node.left, res)
            res.append(node.val)
            inorder(node.right, res)
        l1: list[int] = []
        l2: list[int] = []
        inorder(root1, l1)
        inorder(root2, l2)
        res: list[int] = []
        i = j = 0
        while i < len(l1) and j < len(l2):
            if l1[i] <= l2[j]:
                res.append(l1[i]); i += 1
            else:
                res.append(l2[j]); j += 1
        res.extend(l1[i:])
        res.extend(l2[j:])
        return res
