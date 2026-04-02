import java.util.*;

class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) if (nums[i] == x) idx.add(i);
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++)
            res[i] = queries[i] <= idx.size() ? idx.get(queries[i]-1) : -1;
        return res;
    }
}
