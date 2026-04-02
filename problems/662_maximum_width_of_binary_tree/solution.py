from shared.python.data_structures import TreeNode


class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        from collections import deque
        if not root:
            return 0
        max_width = 0
        queue = deque([(root, 0)])
        while queue:
            level_length = len(queue)
            _, first_index = queue[0]
            for _ in range(level_length):
                node, index = queue.popleft()
                if node.left:
                    queue.append((node.left, 2 * index))
                if node.right:
                    queue.append((node.right, 2 * index + 1))
            max_width = max(max_width, index - first_index + 1)
        return max_width
