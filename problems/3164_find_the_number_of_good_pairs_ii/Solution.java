import java.util.*;

class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int k) {
        Map<Long, Long> cnt = new HashMap<>();
        for (int b : nums2) cnt.merge((long)b * k, 1L, Long::sum);
        long res = 0;
        for (int a : nums1) {
            for (long d = 1; d * d <= a; d++) {
                if (a % d == 0) {
                    if (cnt.containsKey(d)) res += cnt.get(d);
                    if (d != a / d && cnt.containsKey((long)(a / d))) res += cnt.get((long)(a / d));
                }
            }
        }
        return res;
    }
}
