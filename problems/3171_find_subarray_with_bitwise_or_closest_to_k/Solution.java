import java.util.*;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        int res = Integer.MAX_VALUE;
        Set<Integer> curr = new HashSet<>();
        for (int x : nums) {
            Set<Integer> nxt = new HashSet<>();
            nxt.add(x);
            for (int v : curr) nxt.add(v & x);
            for (int v : nxt) res = Math.min(res, Math.abs(v - k));
            curr = nxt;
        }
        return res;
    }
}
