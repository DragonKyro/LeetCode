class Solution {
    public String minimumString(String a, String b, String c) {
        String[] strs = {a, b, c};
        int[][] perms = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
        String best = null;
        for (int[] p : perms) {
            String res = merge(merge(strs[p[0]], strs[p[1]]), strs[p[2]]);
            if (best == null || res.length() < best.length() || (res.length() == best.length() && res.compareTo(best) < 0))
                best = res;
        }
        return best;
    }
    String merge(String s1, String s2) {
        if (s1.contains(s2)) return s1;
        for (int i = 0; i < s1.length(); i++)
            if (s2.startsWith(s1.substring(i))) return s1.substring(0, i) + s2;
        return s1 + s2;
    }
}
