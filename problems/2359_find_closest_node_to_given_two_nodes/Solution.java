import java.util.*;

class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;
        int[] dist1 = getDist(edges, node1, n), dist2 = getDist(edges, node2, n);
        int result = -1, minDist = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (dist1[i] >= 0 && dist2[i] >= 0) {
                int d = Math.max(dist1[i], dist2[i]);
                if (d < minDist) { minDist = d; result = i; }
            }
        }
        return result;
    }
    private int[] getDist(int[] edges, int start, int n) {
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        int d = 0;
        while (start != -1 && dist[start] == -1) {
            dist[start] = d++;
            start = edges[start];
        }
        return dist;
    }
}
