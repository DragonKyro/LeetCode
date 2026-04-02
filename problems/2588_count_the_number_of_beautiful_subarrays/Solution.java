import java.util.*;

class Solution {
    public long beautifulSubarrays(int[] nums) {
        Map<Integer,Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        int xor = 0; long ans = 0;
        for (int n : nums) { xor ^= n; ans += cnt.getOrDefault(xor, 0); cnt.merge(xor, 1, Integer::sum); }
        return ans;
    }
}
