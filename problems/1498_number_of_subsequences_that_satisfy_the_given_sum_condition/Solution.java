import java.util.*;

class Solution {
    public int numSubseq(int[] nums, int target) {
        int MOD = 1_000_000_007;
        Arrays.sort(nums);
        int n = nums.length;
        int[] pow2 = new int[n];
        pow2[0] = 1;
        for (int i = 1; i < n; i++) pow2[i] = pow2[i-1] * 2 % MOD;
        int res = 0, left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] > target) right--;
            else { res = (res + pow2[right - left]) % MOD; left++; }
        }
        return res;
    }
}
