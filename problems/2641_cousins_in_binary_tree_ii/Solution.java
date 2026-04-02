import java.util.*;

class Solution {
    public TreeNode replaceValueInTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root); root.val = 0;
        while (!q.isEmpty()) {
            int sz = q.size(); long sum = 0;
            List<TreeNode> nodes = new ArrayList<>();
            for (int i = 0; i < sz; i++) {
                TreeNode n = q.poll(); nodes.add(n);
                if (n.left != null) { sum += n.left.val; q.offer(n.left); }
                if (n.right != null) { sum += n.right.val; q.offer(n.right); }
            }
            for (TreeNode n : nodes) {
                int sib = (n.left!=null?n.left.val:0)+(n.right!=null?n.right.val:0);
                if (n.left!=null) n.left.val = (int)(sum-sib);
                if (n.right!=null) n.right.val = (int)(sum-sib);
            }
        }
        return root;
    }
}
