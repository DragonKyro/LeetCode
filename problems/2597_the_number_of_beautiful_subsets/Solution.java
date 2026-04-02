import java.util.*;

class Solution {
    int count = 0;
    public int beautifulSubsets(int[] nums, int k) {
        backtrack(nums, k, 0, new HashMap<>());
        return count;
    }
    void backtrack(int[] nums, int k, int idx, Map<Integer,Integer> used) {
        if (idx == nums.length) { if (!used.isEmpty()) count++; return; }
        backtrack(nums, k, idx+1, used);
        if (used.getOrDefault(nums[idx]-k,0)==0 && used.getOrDefault(nums[idx]+k,0)==0) {
            used.merge(nums[idx], 1, Integer::sum);
            backtrack(nums, k, idx+1, used);
            used.merge(nums[idx], -1, Integer::sum);
            if (used.get(nums[idx]) == 0) used.remove(nums[idx]);
        }
    }
}
