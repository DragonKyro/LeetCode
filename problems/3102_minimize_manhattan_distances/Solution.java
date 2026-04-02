import java.util.*;

class Solution {
    public int minimumDistance(int[][] points) {
        int n = points.length;
        int res = Integer.MAX_VALUE;
        int[] candidates = getCandidates(points);
        for (int skip : candidates) res = Math.min(res, calc(points, skip));
        return res;
    }
    private int calc(int[][] points, int skip) {
        int mxS = Integer.MIN_VALUE, mnS = Integer.MAX_VALUE;
        int mxD = Integer.MIN_VALUE, mnD = Integer.MAX_VALUE;
        for (int i = 0; i < points.length; i++) {
            if (i == skip) continue;
            int s = points[i][0] + points[i][1], d = points[i][0] - points[i][1];
            mxS = Math.max(mxS, s); mnS = Math.min(mnS, s);
            mxD = Math.max(mxD, d); mnD = Math.min(mnD, d);
        }
        return Math.max(mxS - mnS, mxD - mnD);
    }
    private int[] getCandidates(int[][] points) {
        Set<Integer> set = new HashSet<>();
        int mxSi=0,mnSi=0,mxDi=0,mnDi=0;
        for (int i = 0; i < points.length; i++) {
            int s = points[i][0]+points[i][1], d = points[i][0]-points[i][1];
            if (s > points[mxSi][0]+points[mxSi][1]) mxSi=i;
            if (s < points[mnSi][0]+points[mnSi][1]) mnSi=i;
            if (d > points[mxDi][0]-points[mxDi][1]) mxDi=i;
            if (d < points[mnDi][0]-points[mnDi][1]) mnDi=i;
        }
        set.add(mxSi); set.add(mnSi); set.add(mxDi); set.add(mnDi);
        return set.stream().mapToInt(Integer::intValue).toArray();
    }
}
