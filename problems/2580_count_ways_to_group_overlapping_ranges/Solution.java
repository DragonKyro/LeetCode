import java.util.*;

class Solution {
    public int countWays(int[][] ranges) {
        Arrays.sort(ranges, (a,b) -> a[0]-b[0]);
        long MOD = 1_000_000_007;
        int groups = 0, end = -1;
        for (int[] r : ranges) { if (r[0] > end) groups++; end = Math.max(end, r[1]); }
        long ans = 1;
        for (int i = 0; i < groups; i++) ans = ans * 2 % MOD;
        return (int) ans;
    }
}
