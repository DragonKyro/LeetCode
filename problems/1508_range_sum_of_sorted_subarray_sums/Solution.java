import java.util.*;

class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int MOD = 1_000_000_007;
        List<Integer> sums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = i; j < n; j++) {
                s += nums[j];
                sums.add(s);
            }
        }
        Collections.sort(sums);
        long res = 0;
        for (int i = left - 1; i < right; i++) res = (res + sums.get(i)) % MOD;
        return (int) res;
    }
}
