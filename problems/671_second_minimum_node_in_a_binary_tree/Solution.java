class Solution {
    long result = Long.MAX_VALUE;
    public int findSecondMinimumValue(TreeNode root) {
        int minVal = root.val;
        dfs(root, minVal);
        return result == Long.MAX_VALUE ? -1 : (int) result;
    }
    private void dfs(TreeNode node, int minVal) {
        if (node == null) return;
        if (node.val > minVal && node.val < result) {
            result = node.val;
        } else if (node.val == minVal) {
            dfs(node.left, minVal);
            dfs(node.right, minVal);
        }
    }
}
