import java.util.*;

class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) map.merge(n, 1, Integer::sum);
        int res = 0;
        for (int key : map.keySet()) {
            if (k == 0 && map.get(key) > 1) res++;
            else if (k > 0 && map.containsKey(key + k)) res++;
        }
        return res;
    }
}
