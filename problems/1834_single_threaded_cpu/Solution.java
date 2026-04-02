import java.util.*;

class Solution {
    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        int[][] indexed = new int[n][3];
        for (int i = 0; i < n; i++) { indexed[i] = new int[]{tasks[i][0], tasks[i][1], i}; }
        Arrays.sort(indexed, (a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        int[] result = new int[n];
        long time = 0;
        int i = 0, ri = 0;
        while (i < n || !pq.isEmpty()) {
            if (pq.isEmpty() && i < n && indexed[i][0] > time) time = indexed[i][0];
            while (i < n && indexed[i][0] <= time) { pq.offer(new int[]{indexed[i][1], indexed[i][2]}); i++; }
            int[] top = pq.poll();
            time += top[0];
            result[ri++] = top[1];
        }
        return result;
    }
}
