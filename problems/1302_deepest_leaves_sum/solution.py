from shared.python.data_structures import TreeNode


class Solution:
    def deepestLeavesSum(self, root: 'TreeNode') -> int:
        from collections import deque
        q = deque([root])
        while q:
            level_sum = 0
            for _ in range(len(q)):
                node = q.popleft()
                level_sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return level_sum
