class Solution {
    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
    private int dfs(TreeNode node, int maxVal) {
        if (node == null) return 0;
        int count = node.val >= maxVal ? 1 : 0;
        int newMax = Math.max(maxVal, node.val);
        return count + dfs(node.left, newMax) + dfs(node.right, newMax);
    }
}
