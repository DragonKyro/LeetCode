import java.util.*;

class Solution {
    public char repeatedCharacter(String s) {
        Set<Character> seen = new HashSet<>();
        for (char c : s.toCharArray()) {
            if (!seen.add(c)) return c;
        }
        return ' ';
    }
}
