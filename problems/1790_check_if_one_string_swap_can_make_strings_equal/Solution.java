import java.util.*;

class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        List<Integer> diffs = new ArrayList<>();
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) diffs.add(i);
        }
        if (diffs.size() == 0) return true;
        if (diffs.size() != 2) return false;
        int i = diffs.get(0), j = diffs.get(1);
        return s1.charAt(i) == s2.charAt(j) && s1.charAt(j) == s2.charAt(i);
    }
}
