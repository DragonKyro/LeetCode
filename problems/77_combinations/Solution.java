import java.util.*;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(1, n, k, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(int start, int n, int k, List<Integer> combo, List<List<Integer>> result) {
        if (combo.size() == k) { result.add(new ArrayList<>(combo)); return; }
        for (int i = start; i <= n; i++) {
            combo.add(i);
            backtrack(i + 1, n, k, combo, result);
            combo.remove(combo.size() - 1);
        }
    }
}
