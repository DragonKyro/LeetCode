class Solution {
    public int countHomogenous(String s) {
        long MOD = 1_000_000_007, result = 0, count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) count++;
            else { result += count * (count + 1) / 2; count = 1; }
        }
        result += count * (count + 1) / 2;
        return (int)(result % MOD);
    }
}
