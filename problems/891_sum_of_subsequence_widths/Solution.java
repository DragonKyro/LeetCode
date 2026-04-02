import java.util.*;

class Solution {
    public int sumSubseqWidths(int[] nums) {
        long MOD = 1_000_000_007;
        Arrays.sort(nums);
        int n = nums.length;
        long result = 0, pow2 = 1;
        for (int i = 0; i < n; i++) {
            result = (result + nums[i] * pow2 - nums[n - 1 - i] * pow2) % MOD;
            pow2 = pow2 * 2 % MOD;
        }
        return (int) ((result + MOD) % MOD);
    }
}
