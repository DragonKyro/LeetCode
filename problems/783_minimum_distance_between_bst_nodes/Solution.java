class Solution {
    int ans = Integer.MAX_VALUE;
    Integer prev = null;

    public int minDiffInBST(TreeNode root) {
        inorder(root);
        return ans;
    }

    private void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        if (prev != null) ans = Math.min(ans, node.val - prev);
        prev = node.val;
        inorder(node.right);
    }
}
