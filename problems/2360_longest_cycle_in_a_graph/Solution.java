class Solution {
    public int longestCycle(int[] edges) {
        int n = edges.length, result = -1, time = 1;
        int[] visited = new int[n];
        for (int i = 0; i < n; i++) {
            if (visited[i] > 0) continue;
            int startTime = time, node = i;
            while (node != -1 && visited[node] == 0) {
                visited[node] = time++;
                node = edges[node];
            }
            if (node != -1 && visited[node] >= startTime)
                result = Math.max(result, time - visited[node]);
        }
        return result;
    }
}
