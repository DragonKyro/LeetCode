import java.util.*;

class Solution {
    public boolean splitArraySameAverage(int[] nums) {
        int n = nums.length, total = 0;
        for (int x : nums) total += x;
        if (n == 1) return false;
        int half = n / 2;
        Set<Integer>[] dp = new HashSet[half + 1];
        for (int i = 0; i <= half; i++) dp[i] = new HashSet<>();
        dp[0].add(0);
        for (int num : nums) {
            for (int k = half; k >= 1; k--) {
                for (int s : dp[k - 1]) dp[k].add(s + num);
            }
        }
        for (int k = 1; k <= half; k++) {
            if (total * k % n == 0 && dp[k].contains(total * k / n)) return true;
        }
        return false;
    }
}
