import java.util.*;

class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] != b[1] ? a[1] - b[1] : b[0] - a[0]);
        List<Integer> res = new ArrayList<>();
        for (int[] interval : intervals) {
            int s = interval[0], e = interval[1];
            if (res.isEmpty() || res.get(res.size() - 1) < s) {
                res.add(e - 1); res.add(e);
            } else if (res.get(res.size() - 2) < s) {
                res.add(e);
            }
        }
        return res.size();
    }
}
