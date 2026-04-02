from shared.python.data_structures import TreeNode


class Solution:
    def averageOfLevels(self, root: TreeNode) -> list[float]:
        from collections import deque
        result = []
        queue = deque([root])
        while queue:
            level_sum = 0
            level_count = len(queue)
            for _ in range(level_count):
                node = queue.popleft()
                level_sum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(level_sum / level_count)
        return result
