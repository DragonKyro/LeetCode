import java.util.*;

class Solution {
    public int minAnagramLength(String s) {
        int n = s.length();
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            int[] base = new int[26];
            for (int i = 0; i < k; i++) base[s.charAt(i)-'a']++;
            boolean ok = true;
            for (int i = k; i < n; i += k) {
                int[] cur = new int[26];
                for (int j = i; j < i+k; j++) cur[s.charAt(j)-'a']++;
                if (!Arrays.equals(base, cur)) { ok = false; break; }
            }
            if (ok) return k;
        }
        return n;
    }
}
