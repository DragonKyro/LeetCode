import java.util.*;

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        Set<Integer> daySet = new HashSet<>();
        for (int d : days) daySet.add(d);
        int last = days[days.length - 1];
        int[] dp = new int[last + 1];
        for (int i = 1; i <= last; i++) {
            if (!daySet.contains(i)) { dp[i] = dp[i - 1]; continue; }
            dp[i] = Math.min(dp[i - 1] + costs[0],
                    Math.min(dp[Math.max(0, i - 7)] + costs[1],
                             dp[Math.max(0, i - 30)] + costs[2]));
        }
        return dp[last];
    }
}
