class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int ans = 0, zeros = 0, ones = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') { if (i > 0 && s.charAt(i-1) == '1') zeros = 0; zeros++; }
            else { ones++; ans = Math.max(ans, 2*Math.min(zeros, ones)); }
        }
        return ans;
    }
}
