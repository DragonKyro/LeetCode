import java.util.*;

class Solution {
    public String bestHand(int[] ranks, char[] suits) {
        Set<Character> s = new HashSet<>();
        for (char c : suits) s.add(c);
        if (s.size() == 1) return "Flush";
        int[] count = new int[14];
        int max = 0;
        for (int r : ranks) { count[r]++; max = Math.max(max, count[r]); }
        if (max >= 3) return "Three of a Kind";
        if (max == 2) return "Pair";
        return "High Card";
    }
}
