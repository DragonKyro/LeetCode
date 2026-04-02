import java.util.*;

class Solution {
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length, n = grid[0].length();
        int allKeys = 0, sr = 0, sc = 0;
        for (int r = 0; r < m; r++) for (int c = 0; c < n; c++) {
            char ch = grid[r].charAt(c);
            if (ch == '@') { sr = r; sc = c; }
            else if (ch >= 'a' && ch <= 'f') allKeys |= 1 << (ch - 'a');
        }
        Queue<int[]> queue = new LinkedList<>();
        Set<Long> visited = new HashSet<>();
        queue.add(new int[]{sr, sc, 0, 0});
        visited.add((long) sr * n * 64 + sc * 64);
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            if (cur[2] == allKeys) return cur[3];
            for (int[] d : dirs) {
                int nr = cur[0]+d[0], nc = cur[1]+d[1];
                if (nr<0||nr>=m||nc<0||nc>=n||grid[nr].charAt(nc)=='#') continue;
                char ch = grid[nr].charAt(nc);
                int nk = cur[2];
                if (ch>='a'&&ch<='f') nk |= 1<<(ch-'a');
                else if (ch>='A'&&ch<='F'&&(cur[2]&(1<<(ch-'A')))==0) continue;
                long key = (long)nr*n*64+nc*64+nk;
                if (visited.add(key)) queue.add(new int[]{nr, nc, nk, cur[3]+1});
            }
        }
        return -1;
    }
}
