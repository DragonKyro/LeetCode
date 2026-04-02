package shared;

public class ListNode {
    public int val;
    public ListNode next;

    public ListNode() {}

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    /** Convert int array to linked list. */
    public static ListNode fromArray(int[] arr) {
        if (arr == null || arr.length == 0) return null;
        ListNode head = new ListNode(arr[0]);
        ListNode curr = head;
        for (int i = 1; i < arr.length; i++) {
            curr.next = new ListNode(arr[i]);
            curr = curr.next;
        }
        return head;
    }

    /** Convert linked list to int array. */
    public static int[] toArray(ListNode head) {
        java.util.List<Integer> list = new java.util.ArrayList<>();
        java.util.Set<ListNode> seen = new java.util.HashSet<>();
        while (head != null && !seen.contains(head)) {
            seen.add(head);
            list.add(head.val);
            head = head.next;
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
