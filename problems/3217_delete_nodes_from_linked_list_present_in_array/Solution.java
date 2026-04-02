import java.util.*;

class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums) set.add(x);
        ListNode dummy = new ListNode(0, head), curr = dummy;
        while (curr.next != null) {
            if (set.contains(curr.next.val)) curr.next = curr.next.next;
            else curr = curr.next;
        }
        return dummy.next;
    }
}
