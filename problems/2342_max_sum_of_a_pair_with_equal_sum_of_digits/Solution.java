import java.util.*;

class Solution {
    public int maximumSum(int[] nums) {
        Map<Integer, Integer> best = new HashMap<>();
        int result = -1;
        for (int num : nums) {
            int ds = 0;
            for (int n = num; n > 0; n /= 10) ds += n % 10;
            if (best.containsKey(ds)) {
                result = Math.max(result, best.get(ds) + num);
                best.put(ds, Math.max(best.get(ds), num));
            } else best.put(ds, num);
        }
        return result;
    }
}
