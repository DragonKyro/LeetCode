import java.util.*;

class Solution {
    public long countSubarrays(int[] nums, int k) {
        long res = 0;
        Map<Integer,Long> curr = new HashMap<>();
        for (int x : nums) {
            Map<Integer,Long> nxt = new HashMap<>();
            for (var e : curr.entrySet())
                nxt.merge(e.getKey() & x, e.getValue(), Long::sum);
            nxt.merge(x, 1L, Long::sum);
            res += nxt.getOrDefault(k, 0L);
            curr = nxt;
        }
        return res;
    }
}
