import java.util.*;

class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        List<List<double[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int i = 0; i < edges.length; i++) {
            graph.get(edges[i][0]).add(new double[]{edges[i][1], succProb[i]});
            graph.get(edges[i][1]).add(new double[]{edges[i][0], succProb[i]});
        }
        double[] dist = new double[n];
        dist[start_node] = 1.0;
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[1], a[1]));
        pq.offer(new double[]{start_node, 1.0});
        while (!pq.isEmpty()) {
            double[] curr = pq.poll();
            int node = (int) curr[0];
            double prob = curr[1];
            if (node == end_node) return prob;
            if (prob < dist[node]) continue;
            for (double[] next : graph.get(node)) {
                int neighbor = (int) next[0];
                double newProb = prob * next[1];
                if (newProb > dist[neighbor]) {
                    dist[neighbor] = newProb;
                    pq.offer(new double[]{neighbor, newProb});
                }
            }
        }
        return 0.0;
    }
}
