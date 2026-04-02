from shared.python.data_structures import ListNode
from shared.python.data_structures import TreeNode


class Solution:
    def isSubPath(self, head: 'ListNode', root: 'TreeNode') -> bool:
        def dfs(head: 'ListNode', node: 'TreeNode') -> bool:
            if not head:
                return True
            if not node:
                return False
            if head.val == node.val:
                if dfs(head.next, node.left) or dfs(head.next, node.right):
                    return True
            return False
        if not root:
            return False
        return dfs(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
