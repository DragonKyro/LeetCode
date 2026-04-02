import java.util.*;

class Solution {
    List<Long> sums = new ArrayList<>();
    public int maxProduct(TreeNode root) {
        long total = totalSum(root);
        long res = 0;
        for (long s : sums) res = Math.max(res, s * (total - s));
        return (int)(res % 1_000_000_007);
    }
    long totalSum(TreeNode node) {
        if (node == null) return 0;
        long s = node.val + totalSum(node.left) + totalSum(node.right);
        sums.add(s);
        return s;
    }
}
