from shared.python.data_structures import TreeNode


class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> list[TreeNode]:
        from collections import defaultdict
        count = defaultdict(int)
        result = []
        def serialize(node):
            if not node:
                return '#'
            s = str(node.val) + ',' + serialize(node.left) + ',' + serialize(node.right)
            count[s] += 1
            if count[s] == 2:
                result.append(node)
            return s
        serialize(root)
        return result
