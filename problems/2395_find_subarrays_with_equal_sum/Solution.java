import java.util.*;

class Solution {
    public boolean findSubarrays(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < nums.length - 1; i++) {
            if (!seen.add(nums[i] + nums[i+1])) return true;
        }
        return false;
    }
}
