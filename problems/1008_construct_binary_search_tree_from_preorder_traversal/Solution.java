class Solution {
    int idx = 0;
    public TreeNode bstFromPreorder(int[] preorder) {
        return build(preorder, Integer.MAX_VALUE);
    }
    private TreeNode build(int[] preorder, int bound) {
        if (idx >= preorder.length || preorder[idx] > bound) return null;
        TreeNode node = new TreeNode(preorder[idx++]);
        node.left = build(preorder, node.val);
        node.right = build(preorder, bound);
        return node;
    }
}
