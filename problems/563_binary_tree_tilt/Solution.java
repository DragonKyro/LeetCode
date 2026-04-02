class Solution {
    int tilt = 0;
    public int findTilt(TreeNode root) {
        dfs(root);
        return tilt;
    }
    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int left = dfs(node.left), right = dfs(node.right);
        tilt += Math.abs(left - right);
        return node.val + left + right;
    }
}
