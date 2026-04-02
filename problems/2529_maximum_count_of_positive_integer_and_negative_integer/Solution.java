class Solution {
    public int countVowelStrings(int n) {
        int[] dp = {1,1,1,1,1};
        for (int i = 1; i < n; i++)
            for (int j = 1; j < 5; j++) dp[j] += dp[j-1];
        int sum = 0;
        for (int d : dp) sum += d;
        return sum;
    }
}
