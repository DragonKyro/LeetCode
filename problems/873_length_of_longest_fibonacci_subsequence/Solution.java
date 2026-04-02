import java.util.*;

class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        Map<Integer, Integer> index = new HashMap<>();
        for (int i = 0; i < n; i++) index.put(arr[i], i);
        int[][] dp = new int[n][n];
        int result = 0;
        for (int k = 0; k < n; k++) for (int j = 0; j < k; j++) {
            int iVal = arr[k] - arr[j];
            if (iVal < arr[j] && index.containsKey(iVal)) {
                int i = index.get(iVal);
                dp[j][k] = Math.max(dp[i][j] + 1, 3);
                result = Math.max(result, dp[j][k]);
            }
        }
        return result;
    }
}
