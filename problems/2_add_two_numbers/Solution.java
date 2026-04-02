class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int val = carry;
            if (l1 != null) { val += l1.val; l1 = l1.next; }
            if (l2 != null) { val += l2.val; l2 = l2.next; }
            carry = val / 10;
            curr.next = new ListNode(val % 10);
            curr = curr.next;
        }
        return dummy.next;
    }
}
