import java.util.*;

class Solution {
    private int postIdx;
    private Map<Integer, Integer> inorderMap = new HashMap<>();
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        postIdx = postorder.length - 1;
        for (int i = 0; i < inorder.length; i++) inorderMap.put(inorder[i], i);
        return helper(postorder, 0, inorder.length - 1);
    }
    private TreeNode helper(int[] postorder, int left, int right) {
        if (left > right) return null;
        int rootVal = postorder[postIdx--];
        TreeNode root = new TreeNode(rootVal);
        int mid = inorderMap.get(rootVal);
        root.right = helper(postorder, mid + 1, right);
        root.left = helper(postorder, left, mid - 1);
        return root;
    }
}
