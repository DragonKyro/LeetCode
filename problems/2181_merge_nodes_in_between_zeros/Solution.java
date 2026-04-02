class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        ListNode node = head.next;
        int total = 0;
        while (node != null) {
            if (node.val == 0) {
                curr.next = new ListNode(total);
                curr = curr.next;
                total = 0;
            } else {
                total += node.val;
            }
            node = node.next;
        }
        return dummy.next;
    }
}
