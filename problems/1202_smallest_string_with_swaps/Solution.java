import java.util.*;

class Solution {
    int[] parent;
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int n = s.length();
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        for (List<Integer> p : pairs) union(p.get(0), p.get(1));
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < n; i++) groups.computeIfAbsent(find(i), k -> new ArrayList<>()).add(i);
        char[] res = s.toCharArray();
        for (List<Integer> indices : groups.values()) {
            List<Character> chars = new ArrayList<>();
            for (int i : indices) chars.add(s.charAt(i));
            Collections.sort(chars);
            Collections.sort(indices);
            for (int i = 0; i < indices.size(); i++) res[indices.get(i)] = chars.get(i);
        }
        return new String(res);
    }
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    void union(int x, int y) { int px = find(x), py = find(y); if (px != py) parent[px] = py; }
}
