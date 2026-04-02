import java.util.*;

class Solution {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        Map<Integer, Integer> rows = new HashMap<>(), cols = new HashMap<>(), d1 = new HashMap<>(), d2 = new HashMap<>();
        Set<Long> lampSet = new HashSet<>();
        for (int[] l : lamps) {
            long key = (long) l[0] * n + l[1];
            if (lampSet.add(key)) {
                rows.merge(l[0], 1, Integer::sum);
                cols.merge(l[1], 1, Integer::sum);
                d1.merge(l[0] - l[1], 1, Integer::sum);
                d2.merge(l[0] + l[1], 1, Integer::sum);
            }
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int r = queries[i][0], c = queries[i][1];
            if (rows.getOrDefault(r, 0) > 0 || cols.getOrDefault(c, 0) > 0 || d1.getOrDefault(r - c, 0) > 0 || d2.getOrDefault(r + c, 0) > 0)
                ans[i] = 1;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr, nc = c + dc;
                    long key = (long) nr * n + nc;
                    if (lampSet.remove(key)) {
                        rows.merge(nr, -1, Integer::sum);
                        cols.merge(nc, -1, Integer::sum);
                        d1.merge(nr - nc, -1, Integer::sum);
                        d2.merge(nr + nc, -1, Integer::sum);
                    }
                }
            }
        }
        return ans;
    }
}
