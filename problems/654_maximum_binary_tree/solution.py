from shared.python.data_structures import TreeNode


class Solution:
    def constructMaximumBinaryTree(self, nums: list[int]) -> TreeNode:
        if not nums:
            return None
        max_idx = nums.index(max(nums))
        root = TreeNode(nums[max_idx])
        root.left = self.constructMaximumBinaryTree(nums[:max_idx])
        root.right = self.constructMaximumBinaryTree(nums[max_idx + 1:])
        return root
