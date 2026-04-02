class Solution {
    public int minSideJumps(int[] obstacles) {
        int[] dp = {1, 0, 1};
        for (int i = 1; i < obstacles.length; i++) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) dp[j] = 1000001;
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] != j + 1) {
                    for (int k = 0; k < 3; k++) {
                        if (k != j && obstacles[i] != k + 1) {
                            dp[j] = Math.min(dp[j], dp[k] + 1);
                        }
                    }
                }
            }
        }
        return Math.min(dp[0], Math.min(dp[1], dp[2]));
    }
}
