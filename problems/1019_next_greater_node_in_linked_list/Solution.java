import java.util.*;

class Solution {
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> vals = new ArrayList<>();
        while (head != null) { vals.add(head.val); head = head.next; }
        int[] ans = new int[vals.size()];
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < vals.size(); i++) {
            while (!stack.isEmpty() && vals.get(stack.peek()) < vals.get(i))
                ans[stack.pop()] = vals.get(i);
            stack.push(i);
        }
        return ans;
    }
}
