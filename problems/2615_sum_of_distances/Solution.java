import java.util.*;

class Solution {
    public long[] distance(int[] nums) {
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < nums.length; i++) groups.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        long[] ans = new long[nums.length];
        for (var indices : groups.values()) {
            int m = indices.size();
            long[] pre = new long[m+1];
            for (int i = 0; i < m; i++) pre[i+1] = pre[i] + indices.get(i);
            for (int i = 0; i < m; i++) {
                long left = (long)indices.get(i)*i - pre[i];
                long right = (pre[m]-pre[i+1]) - (long)indices.get(i)*(m-i-1);
                ans[indices.get(i)] = left + right;
            }
        }
        return ans;
    }
}
