import java.util.*;

class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int[] i : items1) map.merge(i[0], i[1], Integer::sum);
        for (int[] i : items2) map.merge(i[0], i[1], Integer::sum);
        List<List<Integer>> result = new ArrayList<>();
        for (var e : map.entrySet()) result.add(List.of(e.getKey(), e.getValue()));
        return result;
    }
}
