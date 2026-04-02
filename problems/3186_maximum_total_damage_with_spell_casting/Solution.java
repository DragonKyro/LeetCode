import java.util.*;

class Solution {
    public long maximumTotalDamage(int[] power) {
        TreeMap<Integer, Long> cnt = new TreeMap<>();
        for (int p : power) cnt.merge(p, 1L, Long::sum);
        List<Integer> vals = new ArrayList<>(cnt.keySet());
        int n = vals.size();
        long[] dp = new long[n+1];
        int j = 0;
        for (int i = 0; i < n; i++) {
            dp[i+1] = dp[i];
            while (j < i && vals.get(j) < vals.get(i) - 2) j++;
            dp[i+1] = Math.max(dp[i+1], dp[j] + (long)vals.get(i) * cnt.get(vals.get(i)));
        }
        return dp[n];
    }
}
