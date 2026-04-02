import java.util.*;

class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[][] pts = {p1, p2, p3, p4};
        List<Integer> dists = new ArrayList<>();
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++)
                dists.add(dist(pts[i], pts[j]));
        Collections.sort(dists);
        return dists.get(0) > 0 && dists.get(0).equals(dists.get(3)) && dists.get(4).equals(dists.get(5)) && dists.get(4) == 2 * dists.get(0);
    }
    private int dist(int[] a, int[] b) {
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
}
