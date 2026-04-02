class Solution {
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder pathStart = new StringBuilder();
        StringBuilder pathDest = new StringBuilder();
        find(root, startValue, pathStart);
        find(root, destValue, pathDest);
        int i = 0;
        while (i < pathStart.length() && i < pathDest.length() && pathStart.charAt(i) == pathDest.charAt(i)) i++;
        return "U".repeat(pathStart.length() - i) + pathDest.substring(i);
    }
    private boolean find(TreeNode node, int target, StringBuilder path) {
        if (node == null) return false;
        if (node.val == target) return true;
        path.append('L');
        if (find(node.left, target, path)) return true;
        path.deleteCharAt(path.length() - 1);
        path.append('R');
        if (find(node.right, target, path)) return true;
        path.deleteCharAt(path.length() - 1);
        return false;
    }
}
