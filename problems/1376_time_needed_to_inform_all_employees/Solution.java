import java.util.*;

class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Map<Integer, List<Integer>> children = new HashMap<>();
        for (int i = 0; i < n; i++)
            if (manager[i] != -1) children.computeIfAbsent(manager[i], k -> new ArrayList<>()).add(i);
        return dfs(headID, children, informTime);
    }
    int dfs(int node, Map<Integer, List<Integer>> children, int[] informTime) {
        int maxTime = 0;
        for (int child : children.getOrDefault(node, Collections.emptyList()))
            maxTime = Math.max(maxTime, dfs(child, children, informTime));
        return informTime[node] + maxTime;
    }
}
