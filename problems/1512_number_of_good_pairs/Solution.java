import java.util.*;

class Solution {
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        int res = 0;
        for (int n : nums) {
            int c = count.getOrDefault(n, 0);
            res += c;
            count.put(n, c + 1);
        }
        return res;
    }
}
