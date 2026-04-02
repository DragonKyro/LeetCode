import java.util.*;

class Solution {
    public int countPoints(String rings) {
        Set<Character>[] rods = new HashSet[10];
        for (int i = 0; i < 10; i++) rods[i] = new HashSet<>();
        for (int i = 0; i < rings.length(); i += 2) {
            rods[rings.charAt(i + 1) - '0'].add(rings.charAt(i));
        }
        int count = 0;
        for (Set<Character> rod : rods) if (rod.size() == 3) count++;
        return count;
    }
}
