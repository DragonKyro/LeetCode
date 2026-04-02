import java.util.*;

class Solution {
    public int maxLevelSum(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int maxSum = Integer.MIN_VALUE, result = 0, level = 0;
        while (!queue.isEmpty()) {
            level++;
            int size = queue.size(), levelSum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                levelSum += node.val;
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            if (levelSum > maxSum) {
                maxSum = levelSum;
                result = level;
            }
        }
        return result;
    }
}
