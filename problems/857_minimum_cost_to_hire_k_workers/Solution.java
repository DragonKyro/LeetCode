import java.util.*;

class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][2];
        for (int i = 0; i < n; i++) workers[i] = new double[]{(double) wage[i] / quality[i], quality[i]};
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        double result = Double.MAX_VALUE;
        int totalQuality = 0;
        for (double[] w : workers) {
            pq.add((int) w[1]);
            totalQuality += (int) w[1];
            if (pq.size() > k) totalQuality -= pq.poll();
            if (pq.size() == k) result = Math.min(result, totalQuality * w[0]);
        }
        return result;
    }
}
