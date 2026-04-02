import java.util.*;

class Solution {
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);
        int count = 0;
        boolean inComp = false;
        while (head != null) {
            if (set.contains(head.val)) {
                if (!inComp) { count++; inComp = true; }
            } else inComp = false;
            head = head.next;
        }
        return count;
    }
}
