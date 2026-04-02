class Solution {
    public int maxScore(String s) {
        int ones = 0;
        for (char c : s.toCharArray()) if (c == '1') ones++;
        int zeros = 0, best = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '0') zeros++;
            else ones--;
            best = Math.max(best, zeros + ones);
        }
        return best;
    }
}
