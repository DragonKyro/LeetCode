import java.util.*;

class Solution {
    public boolean buddyStrings(String s, String goal) {
        if (s.length() != goal.length()) return false;
        if (s.equals(goal)) {
            int[] count = new int[26];
            for (char c : s.toCharArray()) if (++count[c - 'a'] > 1) return true;
            return false;
        }
        List<Integer> diffs = new ArrayList<>();
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) != goal.charAt(i)) diffs.add(i);
        return diffs.size() == 2 && s.charAt(diffs.get(0)) == goal.charAt(diffs.get(1)) && s.charAt(diffs.get(1)) == goal.charAt(diffs.get(0));
    }
}
