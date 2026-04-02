import java.util.*;

class Solution {
    public int pairSum(ListNode head) {
        List<Integer> values = new ArrayList<>();
        ListNode curr = head;
        while (curr != null) { values.add(curr.val); curr = curr.next; }
        int n = values.size(), max = 0;
        for (int i = 0; i < n / 2; i++) {
            max = Math.max(max, values.get(i) + values.get(n - 1 - i));
        }
        return max;
    }
}
