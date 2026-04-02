class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int ans = 1, j = 0, pairs = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i-1)) pairs++;
            while (pairs > 1) { j++; if (s.charAt(j)==s.charAt(j-1)) pairs--; }
            ans = Math.max(ans, i-j+1);
        }
        return ans;
    }
}
