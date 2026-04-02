import java.util.*;

class Solution {
    int[] parent;
    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (similar(strs[i], strs[j])) union(i, j);
        Set<Integer> groups = new HashSet<>();
        for (int i = 0; i < n; i++) groups.add(find(i));
        return groups.size();
    }
    boolean similar(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) if (a.charAt(i) != b.charAt(i) && ++diff > 2) return false;
        return true;
    }
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    void union(int x, int y) { int px = find(x), py = find(y); if (px != py) parent[px] = py; }
}
