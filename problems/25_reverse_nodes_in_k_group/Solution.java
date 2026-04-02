class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        while (true) {
            ListNode kth = prev;
            for (int i = 0; i < k; i++) {
                kth = kth.next;
                if (kth == null) return dummy.next;
            }
            ListNode curr = prev.next;
            for (int i = 0; i < k - 1; i++) {
                ListNode tmp = curr.next;
                curr.next = tmp.next;
                tmp.next = prev.next;
                prev.next = tmp;
            }
            prev = curr;
        }
    }
}
