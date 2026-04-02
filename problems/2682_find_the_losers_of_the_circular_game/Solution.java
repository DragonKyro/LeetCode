import java.util.*;

class Solution {
    public int[] circularGameLosers(int n, int k) {
        boolean[] vis = new boolean[n];
        int cur = 0, step = 1;
        while (!vis[cur]) { vis[cur] = true; cur = (cur + step * k) % n; step++; }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) if (!vis[i]) res.add(i+1);
        return res.stream().mapToInt(i->i).toArray();
    }
}
