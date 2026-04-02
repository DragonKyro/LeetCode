import java.util.*;

class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int maxMoves = Math.max(stones[n-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2);
        int minMoves = n;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) j++;
            int already = j - i + 1;
            if (already == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                minMoves = Math.min(minMoves, 2);
            else
                minMoves = Math.min(minMoves, n - already);
        }
        return new int[]{minMoves, maxMoves};
    }
}
