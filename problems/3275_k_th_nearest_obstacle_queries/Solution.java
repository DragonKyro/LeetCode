import java.util.*;

class Solution {
    public int[] resultsArray(int[][] queries, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int d = Math.abs(queries[i][0]) + Math.abs(queries[i][1]);
            pq.offer(d);
            if (pq.size() > k) pq.poll();
            res[i] = pq.size() == k ? pq.peek() : -1;
        }
        return res;
    }
}
