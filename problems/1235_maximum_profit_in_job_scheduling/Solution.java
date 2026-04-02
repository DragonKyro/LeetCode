import java.util.*;

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) jobs[i] = new int[]{startTime[i], endTime[i], profit[i]};
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int s = jobs[i-1][0];
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (jobs[mid-1][1] <= s) lo = mid;
                else hi = mid - 1;
            }
            if (lo == 0 && (i == 1 || jobs[0][1] > s)) dp[i] = Math.max(dp[i-1], jobs[i-1][2]);
            else dp[i] = Math.max(dp[i-1], dp[lo] + jobs[i-1][2]);
        }
        return dp[n];
    }
}
