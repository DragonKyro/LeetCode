import java.util.*;

class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);
        int result = -1;
        for (int n : nums) if (n > 0 && set.contains(-n)) result = Math.max(result, n);
        return result;
    }
}
