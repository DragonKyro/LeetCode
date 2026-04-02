import java.util.*;

class Solution {
    Map<Integer, Integer> parent = new HashMap<>();
    public int removeStones(int[][] stones) {
        for (int[] s : stones) union(s[0], ~s[1]);
        Set<Integer> roots = new HashSet<>();
        for (int[] s : stones) roots.add(find(s[0]));
        return stones.length - roots.size();
    }
    int find(int x) {
        parent.putIfAbsent(x, x);
        if (parent.get(x) != x) parent.put(x, find(parent.get(x)));
        return parent.get(x);
    }
    void union(int x, int y) { parent.put(find(x), find(y)); }
}
