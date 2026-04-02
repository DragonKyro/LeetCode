from shared.python.data_structures import TreeNode


class Codec:
    def serialize(self, root):
        if not root:
            return 'null'
        return str(root.val) + ',' + self.serialize(root.left) + ',' + self.serialize(root.right)

    def deserialize(self, data):
        def helper(vals):
            val = next(vals)
            if val == 'null':
                return None
            node = TreeNode(int(val))
            node.left = helper(vals)
            node.right = helper(vals)
            return node
        return helper(iter(data.split(',')))
