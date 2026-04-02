import java.util.*;

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0), b = equations.get(i).get(1);
            graph.computeIfAbsent(a, k -> new HashMap<>()).put(b, values[i]);
            graph.computeIfAbsent(b, k -> new HashMap<>()).put(a, 1.0 / values[i]);
        }
        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++)
            res[i] = bfs(graph, queries.get(i).get(0), queries.get(i).get(1));
        return res;
    }
    double bfs(Map<String, Map<String, Double>> graph, String src, String dst) {
        if (!graph.containsKey(src) || !graph.containsKey(dst)) return -1.0;
        if (src.equals(dst)) return 1.0;
        Queue<Object[]> queue = new LinkedList<>();
        queue.offer(new Object[]{src, 1.0});
        Set<String> visited = new HashSet<>();
        visited.add(src);
        while (!queue.isEmpty()) {
            Object[] cur = queue.poll();
            String node = (String) cur[0];
            double product = (Double) cur[1];
            if (node.equals(dst)) return product;
            for (var entry : graph.get(node).entrySet()) {
                if (visited.add(entry.getKey()))
                    queue.offer(new Object[]{entry.getKey(), product * entry.getValue()});
            }
        }
        return -1.0;
    }
}
