import java.util.*;

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int maxWidth = 0;
        Queue<long[]> queue = new LinkedList<>();
        queue.offer(new long[]{0});
        Queue<TreeNode> nodes = new LinkedList<>();
        nodes.offer(root);
        while (!nodes.isEmpty()) {
            int size = nodes.size();
            long first = queue.peek()[0];
            long last = first;
            for (int i = 0; i < size; i++) {
                TreeNode node = nodes.poll();
                long idx = queue.poll()[0];
                last = idx;
                if (node.left != null) {
                    nodes.offer(node.left);
                    queue.offer(new long[]{2 * idx});
                }
                if (node.right != null) {
                    nodes.offer(node.right);
                    queue.offer(new long[]{2 * idx + 1});
                }
            }
            maxWidth = Math.max(maxWidth, (int)(last - first + 1));
        }
        return maxWidth;
    }
}
