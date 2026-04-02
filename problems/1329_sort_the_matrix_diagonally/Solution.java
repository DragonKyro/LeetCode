import java.util.*;

class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, List<Integer>> d = new HashMap<>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                d.computeIfAbsent(i - j, k -> new ArrayList<>()).add(mat[i][j]);
        for (List<Integer> list : d.values()) Collections.sort(list);
        Map<Integer, Integer> idx = new HashMap<>();
        for (int key : d.keySet()) idx.put(key, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int key = i - j;
                mat[i][j] = d.get(key).get(idx.get(key));
                idx.put(key, idx.get(key) + 1);
            }
        return mat;
    }
}
