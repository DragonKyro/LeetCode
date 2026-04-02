import java.util.*;

class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> dp = new HashMap<>();
        int res = 1;
        for (int x : arr) {
            int val = dp.getOrDefault(x - difference, 0) + 1;
            dp.put(x, val);
            res = Math.max(res, val);
        }
        return res;
    }
}
