import java.util.*;

class Solution {
    public void recoverTree(TreeNode root) {
        TreeNode first = null, second = null, prev = null;
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) { stack.push(curr); curr = curr.left; }
            curr = stack.pop();
            if (prev != null && prev.val > curr.val) {
                if (first == null) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr.right;
        }
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
}
