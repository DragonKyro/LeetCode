import java.util.*;

class Solution {
    public int minStickers(String[] stickers, String target) {
        int n = target.length();
        int N = 1 << n;
        int[] dp = new int[N];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int mask = 0; mask < N; mask++) {
            if (dp[mask] == Integer.MAX_VALUE) continue;
            for (String sticker : stickers) {
                int cur = mask;
                for (char c : sticker.toCharArray()) {
                    for (int i = 0; i < n; i++) {
                        if (((cur >> i) & 1) == 1) continue;
                        if (target.charAt(i) == c) {
                            cur |= (1 << i);
                            break;
                        }
                    }
                }
                dp[cur] = Math.min(dp[cur], dp[mask] + 1);
            }
        }
        return dp[N - 1] == Integer.MAX_VALUE ? -1 : dp[N - 1];
    }
}
