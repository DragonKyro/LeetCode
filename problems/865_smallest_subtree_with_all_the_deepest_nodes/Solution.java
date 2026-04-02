class Solution {
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root)[0];
    }
    TreeNode[] dfs(TreeNode node) {
        if (node == null) return new TreeNode[]{null, null};
        TreeNode[] left = dfs(node.left), right = dfs(node.right);
        int ld = depth(left), rd = depth(right);
        if (ld > rd) return new TreeNode[]{left[0], wrap(ld + 1)};
        if (rd > ld) return new TreeNode[]{right[0], wrap(rd + 1)};
        return new TreeNode[]{node, wrap(ld + 1)};
    }
    int depth(TreeNode[] arr) { return arr[1] == null ? 0 : arr[1].val; }
    TreeNode wrap(int d) { TreeNode n = new TreeNode(d); return n; }
}
