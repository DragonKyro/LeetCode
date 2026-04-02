import java.util.*;

class Solution {
    public int maxPointsInsideSquare(int[][] points, String s) {
        Map<Character, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < points.length; i++) {
            int d = Math.max(Math.abs(points[i][0]), Math.abs(points[i][1]));
            map.computeIfAbsent(s.charAt(i), k -> new ArrayList<>()).add(d);
        }
        int limit = Integer.MAX_VALUE;
        for (var e : map.entrySet()) {
            Collections.sort(e.getValue());
            if (e.getValue().size() >= 2) limit = Math.min(limit, e.getValue().get(1));
        }
        int res = 0;
        for (var e : map.entrySet())
            if (e.getValue().get(0) < limit) res++;
        return res;
    }
}
