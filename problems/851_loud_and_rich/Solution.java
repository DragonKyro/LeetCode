import java.util.*;

class Solution {
    List<List<Integer>> graph;
    int[] answer, quiet;
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        this.quiet = quiet;
        graph = new ArrayList<>();
        answer = new int[n];
        Arrays.fill(answer, -1);
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] r : richer) graph.get(r[1]).add(r[0]);
        for (int i = 0; i < n; i++) dfs(i);
        return answer;
    }
    int dfs(int node) {
        if (answer[node] != -1) return answer[node];
        answer[node] = node;
        for (int nei : graph.get(node)) {
            int cand = dfs(nei);
            if (quiet[cand] < quiet[answer[node]]) answer[node] = cand;
        }
        return answer[node];
    }
}
