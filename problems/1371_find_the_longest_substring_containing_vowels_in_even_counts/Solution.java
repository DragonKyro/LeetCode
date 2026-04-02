import java.util.*;

class Solution {
    public int findTheLongestSubstring(String s) {
        Map<Integer, Integer> first = new HashMap<>();
        first.put(0, -1);
        int state = 0, res = 0;
        String vowels = "aeiou";
        for (int i = 0; i < s.length(); i++) {
            int idx = vowels.indexOf(s.charAt(i));
            if (idx >= 0) state ^= (1 << idx);
            if (first.containsKey(state)) res = Math.max(res, i - first.get(state));
            else first.put(state, i);
        }
        return res;
    }
}
