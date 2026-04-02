import java.util.*;

class Solution {
    List<TreeNode> result = new ArrayList<>();
    Set<Integer> toDeleteSet;
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        toDeleteSet = new HashSet<>();
        for (int val : to_delete) toDeleteSet.add(val);
        dfs(root, true);
        return result;
    }
    private TreeNode dfs(TreeNode node, boolean isRoot) {
        if (node == null) return null;
        boolean deleted = toDeleteSet.contains(node.val);
        if (isRoot && !deleted) result.add(node);
        node.left = dfs(node.left, deleted);
        node.right = dfs(node.right, deleted);
        return deleted ? null : node;
    }
}
