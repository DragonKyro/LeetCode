import java.util.*;

class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = capacity.length;
        int[] remaining = new int[n];
        for (int i = 0; i < n; i++) remaining[i] = capacity[i] - rocks[i];
        Arrays.sort(remaining);
        int count = 0;
        for (int r : remaining) {
            if (additionalRocks >= r) { additionalRocks -= r; count++; }
            else break;
        }
        return count;
    }
}
