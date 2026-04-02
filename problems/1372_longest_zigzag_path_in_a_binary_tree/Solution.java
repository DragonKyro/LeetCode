class Solution {
    int res = 0;
    public int longestZigZag(TreeNode root) {
        dfs(root);
        return res;
    }
    int[] dfs(TreeNode node) {
        if (node == null) return new int[]{-1, -1};
        int[] left = dfs(node.left), right = dfs(node.right);
        int l = left[1] + 1, r = right[0] + 1;
        res = Math.max(res, Math.max(l, r));
        return new int[]{l, r};
    }
}
