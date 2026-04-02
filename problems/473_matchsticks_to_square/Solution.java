import java.util.*;

class Solution {
    public boolean makesquare(int[] matchsticks) {
        int total = 0;
        for (int m : matchsticks) total += m;
        if (total % 4 != 0) return false;
        int side = total / 4;
        Arrays.sort(matchsticks);
        int[] sides = new int[4];
        return backtrack(matchsticks, sides, matchsticks.length - 1, side);
    }
    private boolean backtrack(int[] m, int[] sides, int idx, int side) {
        if (idx < 0) return sides[0] == side && sides[1] == side && sides[2] == side;
        for (int i = 0; i < 4; i++) {
            if (sides[i] + m[idx] <= side) {
                sides[i] += m[idx];
                if (backtrack(m, sides, idx - 1, side)) return true;
                sides[i] -= m[idx];
                if (sides[i] == 0) break;
            }
        }
        return false;
    }
}
