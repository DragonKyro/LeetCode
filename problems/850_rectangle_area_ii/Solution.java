import java.util.*;

class Solution {
    public int rectangleArea(int[][] rectangles) {
        long MOD = 1_000_000_007;
        List<int[]> events = new ArrayList<>();
        for (int[] r : rectangles) {
            events.add(new int[]{r[0], 0, r[1], r[3]});
            events.add(new int[]{r[2], 1, r[1], r[3]});
        }
        events.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        List<int[]> active = new ArrayList<>();
        long result = 0;
        int prevX = events.get(0)[0];
        for (int[] e : events) {
            result = (result + calcY(active) * (e[0] - prevX)) % MOD;
            if (e[1] == 0) active.add(new int[]{e[2], e[3]});
            else active.removeIf(a -> a[0] == e[2] && a[1] == e[3]);
            prevX = e[0];
        }
        return (int) result;
    }
    long calcY(List<int[]> active) {
        List<int[]> sorted = new ArrayList<>(active);
        sorted.sort((a, b) -> a[0] - b[0]);
        long total = 0; int cur = -1;
        for (int[] seg : sorted) {
            int y1 = Math.max(seg[0], cur);
            if (y1 < seg[1]) total += seg[1] - y1;
            cur = Math.max(cur, seg[1]);
        }
        return total;
    }
}
