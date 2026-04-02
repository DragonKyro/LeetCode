class Solution {
    int leftCount = 0, rightCount = 0;
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        find(root, x);
        int parentCount = n - leftCount - rightCount - 1;
        return Math.max(Math.max(leftCount, rightCount), parentCount) > n / 2;
    }
    private int count(TreeNode node) {
        if (node == null) return 0;
        return 1 + count(node.left) + count(node.right);
    }
    private void find(TreeNode node, int x) {
        if (node == null) return;
        if (node.val == x) {
            leftCount = count(node.left);
            rightCount = count(node.right);
            return;
        }
        find(node.left, x);
        find(node.right, x);
    }
}
