class Solution {
    int result = 0;
    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return result;
    }
    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int left = dfs(node.left);
        int right = dfs(node.right);
        int leftPath = (node.left != null && node.left.val == node.val) ? left + 1 : 0;
        int rightPath = (node.right != null && node.right.val == node.val) ? right + 1 : 0;
        result = Math.max(result, leftPath + rightPath);
        return Math.max(leftPath, rightPath);
    }
}
