import java.util.*;

class Solution {
    public int findFinalValue(int[] nums, int original) {
        Set<Integer> s = new HashSet<>();
        for (int n : nums) s.add(n);
        while (s.contains(original)) original *= 2;
        return original;
    }
}
