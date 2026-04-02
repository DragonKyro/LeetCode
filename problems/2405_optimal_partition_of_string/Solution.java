import java.util.*;

class Solution {
    public int partitionString(String s) {
        Set<Character> seen = new HashSet<>();
        int count = 1;
        for (char c : s.toCharArray()) {
            if (!seen.add(c)) { count++; seen.clear(); seen.add(c); }
        }
        return count;
    }
}
