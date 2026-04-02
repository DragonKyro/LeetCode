import java.util.*;

class Solution {
    public int[] numberOfPairs(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int n : nums) count.merge(n, 1, Integer::sum);
        int pairs = 0;
        for (int v : count.values()) pairs += v / 2;
        return new int[]{pairs, nums.length - pairs * 2};
    }
}
