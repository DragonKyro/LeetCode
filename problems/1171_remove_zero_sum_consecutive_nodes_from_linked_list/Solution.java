import java.util.*;

class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        Map<Integer, ListNode> seen = new HashMap<>();
        int prefixSum = 0;
        for (ListNode node = dummy; node != null; node = node.next) {
            prefixSum += node.val;
            seen.put(prefixSum, node);
        }
        prefixSum = 0;
        for (ListNode node = dummy; node != null; node = node.next) {
            prefixSum += node.val;
            node.next = seen.get(prefixSum).next;
        }
        return dummy.next;
    }
}
