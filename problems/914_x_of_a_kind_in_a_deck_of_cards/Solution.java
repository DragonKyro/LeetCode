import java.util.*;

class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int d : deck) count.merge(d, 1, Integer::sum);
        int g = 0;
        for (int v : count.values()) g = gcd(g, v);
        return g >= 2;
    }
    private int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
}
