import java.util.*;

class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] s = {a, b, c};
        Arrays.sort(s);
        if (s[2] - s[0] == 2) return new int[]{0, 0};
        int minMoves = (s[1] - s[0] <= 2 || s[2] - s[1] <= 2) ? 1 : 2;
        int maxMoves = s[2] - s[0] - 2;
        return new int[]{minMoves, maxMoves};
    }
}
