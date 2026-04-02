import java.util.*;

class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        TreeMap<Integer, Integer> cnt = new TreeMap<>();
        for (int x : nums) cnt.merge(x, 1, Integer::sum);
        while (!cnt.isEmpty()) {
            int first = cnt.firstKey();
            for (int i = first; i < first + k; i++) {
                if (!cnt.containsKey(i)) return false;
                cnt.merge(i, -1, Integer::sum);
                if (cnt.get(i) == 0) cnt.remove(i);
            }
        }
        return true;
    }
}
