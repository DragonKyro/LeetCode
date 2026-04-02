import java.util.*;

class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> first = new HashMap<>(), last = new HashMap<>(), count = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            first.putIfAbsent(nums[i], i);
            last.put(nums[i], i);
            count.merge(nums[i], 1, Integer::sum);
        }
        int degree = Collections.max(count.values());
        int result = nums.length;
        for (int num : count.keySet()) {
            if (count.get(num) == degree) {
                result = Math.min(result, last.get(num) - first.get(num) + 1);
            }
        }
        return result;
    }
}
