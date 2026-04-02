class Solution {
    public int minimumChairs(String s) {
        int cur = 0, res = 0;
        for (char c : s.toCharArray()) {
            cur += c == 'E' ? 1 : -1;
            res = Math.max(res, cur);
        }
        return res;
    }
}
