import java.util.*;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int v : rewardValues) set.add(v);
        int[] vals = set.stream().mapToInt(Integer::intValue).toArray();
        int mx = vals[vals.length-1];
        boolean[] dp = new boolean[2*mx];
        dp[0] = true;
        for (int v : vals)
            for (int x = v-1; x >= 0; x--)
                if (dp[x]) dp[x+v] = true;
        for (int i = dp.length-1; i >= 0; i--)
            if (dp[i]) return i;
        return 0;
    }
}
