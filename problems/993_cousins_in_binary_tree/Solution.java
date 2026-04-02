class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        int[] depthX = new int[1], depthY = new int[1];
        TreeNode[] parentX = new TreeNode[1], parentY = new TreeNode[1];
        dfs(root, null, 0, x, depthX, parentX);
        dfs(root, null, 0, y, depthY, parentY);
        return depthX[0] == depthY[0] && parentX[0] != parentY[0];
    }
    private void dfs(TreeNode node, TreeNode parent, int depth, int target, int[] d, TreeNode[] p) {
        if (node == null) return;
        if (node.val == target) { d[0] = depth; p[0] = parent; return; }
        dfs(node.left, node, depth + 1, target, d, p);
        dfs(node.right, node, depth + 1, target, d, p);
    }
}
