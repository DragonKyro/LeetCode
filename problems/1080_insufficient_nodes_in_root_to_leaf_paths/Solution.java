class Solution {
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        return dfs(root, 0, limit);
    }
    private TreeNode dfs(TreeNode node, long current, int limit) {
        if (node == null) return null;
        current += node.val;
        if (node.left == null && node.right == null)
            return current >= limit ? node : null;
        node.left = dfs(node.left, current, limit);
        node.right = dfs(node.right, current, limit);
        return (node.left == null && node.right == null) ? null : node;
    }
}
