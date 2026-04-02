import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), res);
        return res;
    }
    private void backtrack(int[] cands, int remain, int start, List<Integer> path, List<List<Integer>> res) {
        if (remain == 0) { res.add(new ArrayList<>(path)); return; }
        for (int i = start; i < cands.length; i++) {
            if (cands[i] > remain) break;
            if (i > start && cands[i] == cands[i - 1]) continue;
            path.add(cands[i]);
            backtrack(cands, remain - cands[i], i + 1, path, res);
            path.remove(path.size() - 1);
        }
    }
}
