import java.util.*;

class Solution {
    public List<List<String>> printTree(TreeNode root) {
        int h = height(root);
        int cols = (1 << h) - 1;
        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < h; i++) {
            List<String> row = new ArrayList<>();
            for (int j = 0; j < cols; j++) row.add("");
            result.add(row);
        }
        fill(root, 0, 0, cols - 1, result);
        return result;
    }
    private int height(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(height(node.left), height(node.right));
    }
    private void fill(TreeNode node, int r, int lo, int hi, List<List<String>> result) {
        if (node == null) return;
        int mid = (lo + hi) / 2;
        result.get(r).set(mid, String.valueOf(node.val));
        fill(node.left, r + 1, lo, mid - 1, result);
        fill(node.right, r + 1, mid + 1, hi, result);
    }
}
