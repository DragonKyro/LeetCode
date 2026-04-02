import java.util.*;

class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n <= 2) return n;
        int result = 2;
        for (int i = 0; i < n; i++) {
            Map<String, Integer> slopes = new HashMap<>();
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(Math.abs(dx), Math.abs(dy));
                if (g != 0) { dx /= g; dy /= g; }
                if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
                String key = dx + "," + dy;
                slopes.put(key, slopes.getOrDefault(key, 0) + 1);
            }
            for (int count : slopes.values()) result = Math.max(result, count + 1);
        }
        return result;
    }
    private int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
}
