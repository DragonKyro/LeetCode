import java.util.*;

class Solution {
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int[] p : points) set.add(p[0]);
        int[] xs = set.stream().mapToInt(Integer::intValue).toArray();
        int res = 0, i = 0;
        while (i < xs.length) {
            int start = xs[i];
            res++;
            while (i < xs.length && xs[i] <= start + w) i++;
        }
        return res;
    }
}
