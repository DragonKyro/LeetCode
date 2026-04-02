class Solution {
    int total = 0;
    public TreeNode bstToGst(TreeNode root) {
        if (root != null) {
            bstToGst(root.right);
            total += root.val;
            root.val = total;
            bstToGst(root.left);
        }
        return root;
    }
}
