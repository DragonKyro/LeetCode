class Solution {
    public int maxAncestorDiff(TreeNode root) {
        return dfs(root, root.val, root.val);
    }
    private int dfs(TreeNode node, int mn, int mx) {
        if (node == null) return mx - mn;
        mn = Math.min(mn, node.val);
        mx = Math.max(mx, node.val);
        return Math.max(dfs(node.left, mn, mx), dfs(node.right, mn, mx));
    }
}
