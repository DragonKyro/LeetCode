import java.util.*;

class Solution {
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, (a, b) -> b.length() - a.length());
        for (int i = 0; i < strs.length; i++) {
            boolean unique = true;
            for (int j = 0; j < strs.length; j++) {
                if (i != j && isSubseq(strs[i], strs[j])) { unique = false; break; }
            }
            if (unique) return strs[i].length();
        }
        return -1;
    }
    private boolean isSubseq(String s, String t) {
        int i = 0;
        for (int j = 0; j < t.length() && i < s.length(); j++) {
            if (s.charAt(i) == t.charAt(j)) i++;
        }
        return i == s.length();
    }
}
