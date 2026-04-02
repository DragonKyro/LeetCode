import java.util.*;

class Solution {
    public int[][] outerTrees(int[][] trees) {
        Arrays.sort(trees, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        int n = trees.length;
        if (n <= 1) return trees;
        List<int[]> hull = new ArrayList<>();
        for (int[] p : trees) {
            while (hull.size() >= 2 && cross(hull.get(hull.size()-2), hull.get(hull.size()-1), p) < 0)
                hull.remove(hull.size()-1);
            hull.add(p);
        }
        int lower = hull.size();
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > lower && cross(hull.get(hull.size()-2), hull.get(hull.size()-1), trees[i]) < 0)
                hull.remove(hull.size()-1);
            hull.add(trees[i]);
        }
        Set<String> seen = new HashSet<>();
        List<int[]> res = new ArrayList<>();
        for (int[] p : hull) {
            String key = p[0] + "," + p[1];
            if (seen.add(key)) res.add(p);
        }
        return res.toArray(new int[0][]);
    }
    private int cross(int[] o, int[] a, int[] b) {
        return (a[0]-o[0])*(b[1]-o[1]) - (a[1]-o[1])*(b[0]-o[0]);
    }
}
