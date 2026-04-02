import java.util.*;

class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        long area = 0;
        Set<String> corners = new HashSet<>();
        for (int[] r : rectangles) {
            area += (long)(r[2] - r[0]) * (r[3] - r[1]);
            String[] cs = {r[0]+","+r[1], r[0]+","+r[3], r[2]+","+r[1], r[2]+","+r[3]};
            for (String c : cs) {
                if (!corners.add(c)) corners.remove(c);
            }
        }
        if (corners.size() != 4) return false;
        int x1 = Integer.MAX_VALUE, y1 = Integer.MAX_VALUE, x2 = Integer.MIN_VALUE, y2 = Integer.MIN_VALUE;
        for (String c : corners) {
            String[] parts = c.split(",");
            int x = Integer.parseInt(parts[0]), y = Integer.parseInt(parts[1]);
            x1 = Math.min(x1, x); y1 = Math.min(y1, y);
            x2 = Math.max(x2, x); y2 = Math.max(y2, y);
        }
        return area == (long)(x2 - x1) * (y2 - y1);
    }
}
