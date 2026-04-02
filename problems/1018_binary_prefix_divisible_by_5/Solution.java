import java.util.*;

class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> result = new ArrayList<>();
        int val = 0;
        for (int n : nums) {
            val = (val * 2 + n) % 5;
            result.add(val == 0);
        }
        return result;
    }
}
