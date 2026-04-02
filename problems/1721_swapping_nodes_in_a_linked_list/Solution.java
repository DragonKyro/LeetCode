class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode first = head;
        for (int i = 0; i < k - 1; i++) first = first.next;
        ListNode node1 = first;
        ListNode second = head;
        while (first.next != null) {
            first = first.next;
            second = second.next;
        }
        int temp = node1.val;
        node1.val = second.val;
        second.val = temp;
        return head;
    }
}
