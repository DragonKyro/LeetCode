import java.util.*;

class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int lo = 1, hi = position[position.length - 1] - position[0];
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (canPlace(position, m, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
    private boolean canPlace(int[] position, int m, int dist) {
        int count = 1, last = position[0];
        for (int i = 1; i < position.length; i++) {
            if (position[i] - last >= dist) { count++; last = position[i]; }
            if (count >= m) return true;
        }
        return false;
    }
}
