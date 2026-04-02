import java.util.*;

class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        Set<Long> obs = new HashSet<>();
        for (int[] o : obstacles) obs.add((long) o[0] * 60001 + o[1]);
        int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0, result = 0;
        for (int cmd : commands) {
            if (cmd == -2) di = (di + 3) % 4;
            else if (cmd == -1) di = (di + 1) % 4;
            else for (int i = 0; i < cmd; i++) {
                int nx = x + dx[di], ny = y + dy[di];
                if (!obs.contains((long) nx * 60001 + ny)) { x = nx; y = ny; result = Math.max(result, x*x+y*y); }
            }
        }
        return result;
    }
}
