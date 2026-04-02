import java.util.*;

class Solution {
    public String longestDupSubstring(String s) {
        int lo = 0, hi = s.length() - 1;
        String result = "";
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            String dup = check(s, mid);
            if (!dup.isEmpty()) { result = dup; lo = mid + 1; }
            else hi = mid - 1;
        }
        return result;
    }
    private String check(String s, int len) {
        if (len == 0) return "";
        long MOD = (1L << 31) - 1, base = 26, h = 0;
        long power = 1;
        for (int i = 0; i < len; i++) power = power * base % MOD;
        Map<Long, List<Integer>> seen = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            h = (h * base + s.charAt(i) - 'a') % MOD;
            if (i >= len) h = (h - (s.charAt(i - len) - 'a') * power % MOD + MOD) % MOD;
            if (i >= len - 1) {
                List<Integer> list = seen.getOrDefault(h, new ArrayList<>());
                for (int j : list)
                    if (s.substring(j, j + len).equals(s.substring(i - len + 1, i + 1)))
                        return s.substring(j, j + len);
                list.add(i - len + 1);
                seen.put(h, list);
            }
        }
        return "";
    }
}
