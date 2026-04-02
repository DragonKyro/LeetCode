import java.util.*;

class Solution {
    public int maximumLength(int[] nums, int k) {
        Map<Integer,Integer>[] dpVal = new HashMap[k+1];
        int[] best = new int[k+1];
        for (int j = 0; j <= k; j++) dpVal[j] = new HashMap<>();
        int res = 0;
        for (int x : nums) {
            for (int j = k; j >= 0; j--) {
                int cur = dpVal[j].getOrDefault(x, 0) + 1;
                if (j > 0) cur = Math.max(cur, best[j-1] + 1);
                dpVal[j].merge(x, cur, Math::max);
                best[j] = Math.max(best[j], cur);
                res = Math.max(res, cur);
            }
        }
        return res;
    }
}
