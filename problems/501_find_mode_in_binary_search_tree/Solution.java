import java.util.*;

class Solution {
    Integer prev = null;
    int count = 0, maxCount = 0;
    List<Integer> modes = new ArrayList<>();
    
    public int[] findMode(TreeNode root) {
        inorder(root);
        int[] res = new int[modes.size()];
        for (int i = 0; i < modes.size(); i++) res[i] = modes.get(i);
        return res;
    }
    
    private void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        if (prev != null && prev == node.val) count++;
        else count = 1;
        if (count > maxCount) {
            maxCount = count;
            modes.clear();
            modes.add(node.val);
        } else if (count == maxCount) {
            modes.add(node.val);
        }
        prev = node.val;
        inorder(node.right);
    }
}
