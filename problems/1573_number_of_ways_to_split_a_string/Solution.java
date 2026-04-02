class Solution {
    public int numWays(String s) {
        long MOD = 1_000_000_007;
        int ones = 0;
        for (char c : s.toCharArray()) if (c == '1') ones++;
        if (ones % 3 != 0) return 0;
        int n = s.length();
        if (ones == 0) return (int)((long)(n - 1) * (n - 2) / 2 % MOD);
        int target = ones / 3;
        long ways1 = 0, ways2 = 0;
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') count++;
            if (count == target) ways1++;
            if (count == 2 * target) ways2++;
        }
        return (int)(ways1 * ways2 % MOD);
    }
}
