class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int len = 0;
        ListNode cur = head;
        while (cur != null) { len++; cur = cur.next; }
        int width = len / k, extra = len % k;
        ListNode[] result = new ListNode[k];
        cur = head;
        for (int i = 0; i < k; i++) {
            result[i] = cur;
            int size = width + (i < extra ? 1 : 0);
            for (int j = 0; j < size - 1; j++) cur = cur.next;
            if (cur != null) {
                ListNode next = cur.next;
                cur.next = null;
                cur = next;
            }
        }
        return result;
    }
}
