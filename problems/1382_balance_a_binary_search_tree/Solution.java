import java.util.*;

class Solution {
    List<Integer> nodes = new ArrayList<>();
    public TreeNode balanceBST(TreeNode root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
    void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left); nodes.add(node.val); inorder(node.right);
    }
    TreeNode build(int lo, int hi) {
        if (lo > hi) return null;
        int mid = (lo + hi) / 2;
        TreeNode node = new TreeNode(nodes.get(mid));
        node.left = build(lo, mid - 1);
        node.right = build(mid + 1, hi);
        return node;
    }
}
