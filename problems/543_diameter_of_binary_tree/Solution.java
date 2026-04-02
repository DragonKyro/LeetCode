class Solution {
    int ans = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return ans;
    }
    private int depth(TreeNode node) {
        if (node == null) return 0;
        int left = depth(node.left), right = depth(node.right);
        ans = Math.max(ans, left + right);
        return 1 + Math.max(left, right);
    }
}
