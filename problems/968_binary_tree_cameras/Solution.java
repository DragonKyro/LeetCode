class Solution {
    int result = 0;
    public int minCameraCover(TreeNode root) {
        if (dfs(root) == 0) result++;
        return result;
    }
    private int dfs(TreeNode node) {
        if (node == null) return 1;
        int left = dfs(node.left), right = dfs(node.right);
        if (left == 0 || right == 0) { result++; return 2; }
        if (left == 2 || right == 2) return 1;
        return 0;
    }
}
