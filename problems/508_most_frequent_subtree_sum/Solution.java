import java.util.*;

class Solution {
    Map<Integer, Integer> count = new HashMap<>();
    int maxFreq = 0;
    
    public int[] findFrequentTreeSum(TreeNode root) {
        dfs(root);
        List<Integer> res = new ArrayList<>();
        for (var entry : count.entrySet()) {
            if (entry.getValue() == maxFreq) res.add(entry.getKey());
        }
        return res.stream().mapToInt(i -> i).toArray();
    }
    
    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int s = node.val + dfs(node.left) + dfs(node.right);
        count.merge(s, 1, Integer::sum);
        maxFreq = Math.max(maxFreq, count.get(s));
        return s;
    }
}
