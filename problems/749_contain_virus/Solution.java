import java.util.*;

class Solution {
    public int containVirus(int[][] isInfected) {
        int m = isInfected.length, n = isInfected[0].length, walls = 0;
        while (true) {
            boolean[][] visited = new boolean[m][n];
            List<Set<Integer>> regions = new ArrayList<>(), frontiers = new ArrayList<>();
            List<Integer> perimeters = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        Set<Integer> region = new HashSet<>(), frontier = new HashSet<>();
                        int[] perim = {0};
                        Queue<int[]> queue = new LinkedList<>();
                        queue.offer(new int[]{i, j}); visited[i][j] = true;
                        while (!queue.isEmpty()) {
                            int[] cell = queue.poll();
                            region.add(cell[0] * n + cell[1]);
                            for (int[] d : new int[][]{{0,1},{0,-1},{1,0},{-1,0}}) {
                                int nr = cell[0]+d[0], nc = cell[1]+d[1];
                                if (nr>=0&&nr<m&&nc>=0&&nc<n) {
                                    if (isInfected[nr][nc]==0) { frontier.add(nr*n+nc); perim[0]++; }
                                    else if (isInfected[nr][nc]==1&&!visited[nr][nc]) { visited[nr][nc]=true; queue.offer(new int[]{nr,nc}); }
                                }
                            }
                        }
                        regions.add(region); frontiers.add(frontier); perimeters.add(perim[0]);
                    }
                }
            }
            if (regions.isEmpty()) break;
            int idx = 0;
            for (int i = 1; i < frontiers.size(); i++)
                if (frontiers.get(i).size() > frontiers.get(idx).size()) idx = i;
            walls += perimeters.get(idx);
            for (int code : regions.get(idx)) isInfected[code/n][code%n] = -1;
            boolean anyFrontier = false;
            for (int i = 0; i < regions.size(); i++) {
                if (i == idx) continue;
                for (int code : frontiers.get(i)) { isInfected[code/n][code%n] = 1; anyFrontier = true; }
            }
            if (!anyFrontier) break;
        }
        return walls;
    }
}
