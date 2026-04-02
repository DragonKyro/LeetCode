import java.util.*;

class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        List<Long> sums = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            long s = 0; int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode n = q.poll(); s += n.val;
                if (n.left != null) q.offer(n.left);
                if (n.right != null) q.offer(n.right);
            }
            sums.add(s);
        }
        if (k > sums.size()) return -1;
        Collections.sort(sums, Collections.reverseOrder());
        return sums.get(k-1);
    }
}
