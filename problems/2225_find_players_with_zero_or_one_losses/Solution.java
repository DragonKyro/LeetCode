import java.util.*;

class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> losses = new TreeMap<>();
        for (int[] m : matches) {
            losses.putIfAbsent(m[0], 0);
            losses.merge(m[1], 1, Integer::sum);
        }
        List<Integer> noLoss = new ArrayList<>(), oneLoss = new ArrayList<>();
        for (var e : losses.entrySet()) {
            if (e.getValue() == 0) noLoss.add(e.getKey());
            else if (e.getValue() == 1) oneLoss.add(e.getKey());
        }
        return List.of(noLoss, oneLoss);
    }
}
