import java.util.*;

class Solution {
    public int minSubarray(int[] nums, int p) {
        long total = 0;
        for (int n : nums) total += n;
        int rem = (int)(total % p);
        if (rem == 0) return 0;
        Map<Integer, Integer> prefix = new HashMap<>();
        prefix.put(0, -1);
        long cur = 0;
        int res = nums.length;
        for (int i = 0; i < nums.length; i++) {
            cur = (cur + nums[i]) % p;
            int target = (int)((cur - rem + p) % p);
            if (prefix.containsKey(target)) res = Math.min(res, i - prefix.get(target));
            prefix.put((int)cur, i);
        }
        return res < nums.length ? res : -1;
    }
}
