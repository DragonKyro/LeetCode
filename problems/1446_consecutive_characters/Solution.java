class Solution {
    public int maxPower(String s) {
        int res = 1, cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                cur++;
                res = Math.max(res, cur);
            } else {
                cur = 1;
            }
        }
        return res;
    }
}
