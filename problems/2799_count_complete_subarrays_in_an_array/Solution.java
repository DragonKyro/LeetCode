import java.util.*;

class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> all = new HashSet<>();
        for (int n : nums) all.add(n);
        int total = all.size(), n = nums.length, ans = 0;
        for (int i = 0; i < n; i++) {
            Set<Integer> s = new HashSet<>();
            for (int j = i; j < n; j++) {
                s.add(nums[j]);
                if (s.size() == total) { ans += n - j; break; }
            }
        }
        return ans;
    }
}
