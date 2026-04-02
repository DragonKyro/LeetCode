import java.util.*;

class Solution {
    long fuel = 0;
    public long minimumFuelCost(int[][] roads, int seats) {
        List<List<Integer>> graph = new ArrayList<>();
        int n = roads.length + 1;
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] r : roads) { graph.get(r[0]).add(r[1]); graph.get(r[1]).add(r[0]); }
        dfs(0, -1, graph, seats);
        return fuel;
    }
    long dfs(int node, int parent, List<List<Integer>> graph, int seats) {
        long people = 1;
        for (int nb : graph.get(node)) {
            if (nb != parent) people += dfs(nb, node, graph, seats);
        }
        if (node != 0) fuel += (people + seats - 1) / seats;
        return people;
    }
}
