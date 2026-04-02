import java.util.*;

class Solution {
    public int countOfPairs(int[] nums) {
        int MOD = 1_000_000_007, n = nums.length;
        long[] dp = new long[nums[0]+1];
        Arrays.fill(dp, 1);
        for (int i = 1; i < n; i++) {
            long[] ndp = new long[nums[i]+1];
            long prefix = 0;
            int k = 0;
            for (int j = 0; j <= nums[i]; j++) {
                int bound = Math.min(j, nums[i-1]-nums[i]+j);
                while (k <= bound && k <= nums[i-1]) { prefix = (prefix+dp[k])%MOD; k++; }
                ndp[j] = prefix;
            }
            dp = ndp;
        }
        long res = 0;
        for (long v : dp) res = (res+v)%MOD;
        return (int)res;
    }
}
