import java.util.*;

class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length, target = (1 << n) - 1;
        Queue<int[]> queue = new LinkedList<>();
        Set<Long> visited = new HashSet<>();
        for (int i = 0; i < n; i++) {
            queue.add(new int[]{i, 1 << i, 0});
            visited.add((long) i * (target + 1) + (1 << i));
        }
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            if (cur[1] == target) return cur[2];
            for (int nei : graph[cur[0]]) {
                int newMask = cur[1] | (1 << nei);
                long key = (long) nei * (target + 1) + newMask;
                if (visited.add(key)) queue.add(new int[]{nei, newMask, cur[2] + 1});
            }
        }
        return -1;
    }
}
