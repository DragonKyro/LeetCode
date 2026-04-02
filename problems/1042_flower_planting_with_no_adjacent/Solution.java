import java.util.*;

class Solution {
    public int[] gardenNoAdj(int n, int[][] paths) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] p : paths) { graph.get(p[0]-1).add(p[1]-1); graph.get(p[1]-1).add(p[0]-1); }
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            Set<Integer> used = new HashSet<>();
            for (int j : graph.get(i)) used.add(result[j]);
            for (int c = 1; c <= 4; c++) {
                if (!used.contains(c)) { result[i] = c; break; }
            }
        }
        return result;
    }
}
