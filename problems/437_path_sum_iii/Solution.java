import java.util.*;

class Solution {
    private Map<Long, Integer> prefix = new HashMap<>();
    private int targetSum;
    public int pathSum(TreeNode root, int targetSum) {
        this.targetSum = targetSum;
        prefix.put(0L, 1);
        return dfs(root, 0L);
    }
    private int dfs(TreeNode node, long currSum) {
        if (node == null) return 0;
        currSum += node.val;
        int count = prefix.getOrDefault(currSum - targetSum, 0);
        prefix.merge(currSum, 1, Integer::sum);
        count += dfs(node.left, currSum);
        count += dfs(node.right, currSum);
        prefix.merge(currSum, -1, Integer::sum);
        return count;
    }
}
