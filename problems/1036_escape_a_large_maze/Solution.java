import java.util.*;

class Solution {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        Set<Long> blockedSet = new HashSet<>();
        for (int[] b : blocked) blockedSet.add((long)b[0] * 1000000 + b[1]);
        int limit = blocked.length * (blocked.length - 1) / 2;
        return bfs(blockedSet, source, target, limit) && bfs(blockedSet, target, source, limit);
    }
    private boolean bfs(Set<Long> blocked, int[] start, int[] end, int limit) {
        Queue<long[]> queue = new LinkedList<>();
        Set<Long> visited = new HashSet<>();
        long key = (long)start[0] * 1000000 + start[1];
        queue.add(new long[]{start[0], start[1]});
        visited.add(key);
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!queue.isEmpty()) {
            if (visited.size() > limit) return true;
            long[] cur = queue.poll();
            int r = (int)cur[0], c = (int)cur[1];
            if (r == end[0] && c == end[1]) return true;
            for (int[] d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                long nk = (long)nr * 1000000 + nc;
                if (nr >= 0 && nr < 1000000 && nc >= 0 && nc < 1000000 && !blocked.contains(nk) && visited.add(nk))
                    queue.add(new long[]{nr, nc});
            }
        }
        return false;
    }
}
