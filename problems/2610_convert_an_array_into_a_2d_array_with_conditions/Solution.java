import java.util.*;

class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        Map<Integer,Integer> cnt = new HashMap<>();
        for (int n : nums) cnt.merge(n, 1, Integer::sum);
        List<List<Integer>> res = new ArrayList<>();
        while (!cnt.isEmpty()) {
            List<Integer> row = new ArrayList<>(cnt.keySet());
            res.add(row);
            for (int k : row) { cnt.merge(k, -1, Integer::sum); if (cnt.get(k)==0) cnt.remove(k); }
        }
        return res;
    }
}
