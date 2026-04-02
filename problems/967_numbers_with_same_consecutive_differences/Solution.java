import java.util.*;

class Solution {
    public int[] numsSameConsecDiff(int n, int k) {
        List<Integer> curr = new ArrayList<>();
        for (int i = 1; i <= 9; i++) curr.add(i);
        for (int level = 1; level < n; level++) {
            List<Integer> next = new ArrayList<>();
            for (int num : curr) {
                int last = num % 10;
                if (last + k <= 9) next.add(num * 10 + last + k);
                if (k != 0 && last - k >= 0) next.add(num * 10 + last - k);
            }
            curr = next;
        }
        return curr.stream().mapToInt(i -> i).toArray();
    }
}
