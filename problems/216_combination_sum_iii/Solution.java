import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(res, new ArrayList<>(), k, n, 1);
        return res;
    }

    private void backtrack(List<List<Integer>> res, List<Integer> path, int k, int remain, int start) {
        if (path.size() == k) {
            if (remain == 0) res.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > remain) break;
            path.add(i);
            backtrack(res, path, k, remain - i, i + 1);
            path.remove(path.size() - 1);
        }
    }
}
