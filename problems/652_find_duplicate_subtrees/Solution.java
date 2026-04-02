import java.util.*;

class Solution {
    Map<String, Integer> count = new HashMap<>();
    List<TreeNode> result = new ArrayList<>();
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        serialize(root);
        return result;
    }
    private String serialize(TreeNode node) {
        if (node == null) return "#";
        String s = node.val + "," + serialize(node.left) + "," + serialize(node.right);
        count.put(s, count.getOrDefault(s, 0) + 1);
        if (count.get(s) == 2) result.add(node);
        return s;
    }
}
