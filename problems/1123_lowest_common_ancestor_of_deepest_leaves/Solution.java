class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).getValue();
    }
    private AbstractMap.SimpleEntry<Integer, TreeNode> dfs(TreeNode node) {
        if (node == null) return new AbstractMap.SimpleEntry<>(0, null);
        var left = dfs(node.left);
        var right = dfs(node.right);
        if (left.getKey().equals(right.getKey())) return new AbstractMap.SimpleEntry<>(left.getKey() + 1, node);
        if (left.getKey() > right.getKey()) return new AbstractMap.SimpleEntry<>(left.getKey() + 1, left.getValue());
        return new AbstractMap.SimpleEntry<>(right.getKey() + 1, right.getValue());
    }
}
