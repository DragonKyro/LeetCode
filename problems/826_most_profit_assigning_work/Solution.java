import java.util.*;

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int[][] jobs = new int[n][2];
        for (int i = 0; i < n; i++) jobs[i] = new int[]{difficulty[i], profit[i]};
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        Arrays.sort(worker);
        int result = 0, best = 0, j = 0;
        for (int w : worker) {
            while (j < n && jobs[j][0] <= w) best = Math.max(best, jobs[j++][1]);
            result += best;
        }
        return result;
    }
}
