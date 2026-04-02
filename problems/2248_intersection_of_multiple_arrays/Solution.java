import java.util.*;

class Solution {
    public List<Integer> intersection(int[][] nums) {
        Map<Integer, Integer> count = new TreeMap<>();
        for (int[] arr : nums)
            for (int x : arr) count.merge(x, 1, Integer::sum);
        List<Integer> res = new ArrayList<>();
        for (var e : count.entrySet())
            if (e.getValue() == nums.length) res.add(e.getKey());
        return res;
    }
}
