class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        while (prev.next != null && prev.next.next != null) {
            ListNode a = prev.next, b = prev.next.next;
            prev.next = b;
            a.next = b.next;
            b.next = a;
            prev = a;
        }
        return dummy.next;
    }
}
