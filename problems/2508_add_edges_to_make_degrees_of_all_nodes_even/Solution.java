import java.util.*;

class Solution {
    public boolean isPossible(int n, List<List<Integer>> edges) {
        Set<Integer>[] adj = new HashSet[n + 1];
        for (int i = 0; i <= n; i++) adj[i] = new HashSet<>();
        for (var e : edges) { adj[e.get(0)].add(e.get(1)); adj[e.get(1)].add(e.get(0)); }
        List<Integer> odd = new ArrayList<>();
        for (int i = 1; i <= n; i++) if (adj[i].size() % 2 == 1) odd.add(i);
        if (odd.size() == 0) return true;
        if (odd.size() == 2) {
            int a = odd.get(0), b = odd.get(1);
            if (!adj[a].contains(b)) return true;
            for (int i = 1; i <= n; i++) if (i!=a&&i!=b&&!adj[i].contains(a)&&!adj[i].contains(b)) return true;
            return false;
        }
        if (odd.size() == 4) {
            int a=odd.get(0),b=odd.get(1),c=odd.get(2),d=odd.get(3);
            return (!adj[a].contains(b)&&!adj[c].contains(d))||(!adj[a].contains(c)&&!adj[b].contains(d))||(!adj[a].contains(d)&&!adj[b].contains(c));
        }
        return false;
    }
}
