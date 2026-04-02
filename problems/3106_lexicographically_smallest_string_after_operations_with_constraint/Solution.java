class Solution {
    public String getSmallestString(String s, int k) {
        char[] res = s.toCharArray();
        for (int i = 0; i < res.length; i++) {
            int dist = Math.min(res[i] - 'a', 'z' - res[i] + 1);
            if (dist <= k) { res[i] = 'a'; k -= dist; }
            else { res[i] = (char)(res[i] - k); k = 0; }
        }
        return new String(res);
    }
}
