import java.util.*;

class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        for (int i = 0; i < depth - 2; i++) {
            int size = queue.size();
            for (int j = 0; j < size; j++) {
                TreeNode node = queue.poll();
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
        }
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            TreeNode left = new TreeNode(val);
            left.left = node.left;
            node.left = left;
            TreeNode right = new TreeNode(val);
            right.right = node.right;
            node.right = right;
        }
        return root;
    }
}
