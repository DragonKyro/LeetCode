import java.util.*;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int running = 0;
        for (int i = 0; i < nums.length; i++) {
            running += nums[i];
            int mod = running % k;
            if (map.containsKey(mod)) {
                if (i - map.get(mod) >= 2) return true;
            } else {
                map.put(mod, i);
            }
        }
        return false;
    }
}
