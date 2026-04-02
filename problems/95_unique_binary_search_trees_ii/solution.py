from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def generateTrees(self, n: int) -> list[Optional[TreeNode]]:
        if n == 0:
            return []

        def generate(start: int, end: int) -> list[Optional[TreeNode]]:
            if start > end:
                return [None]
            trees: list[Optional[TreeNode]] = []
            for i in range(start, end + 1):
                left_trees = generate(start, i - 1)
                right_trees = generate(i + 1, end)
                for l in left_trees:
                    for r in right_trees:
                        root = TreeNode(i)
                        root.left = l
                        root.right = r
                        trees.append(root)
            return trees

        return generate(1, n)
