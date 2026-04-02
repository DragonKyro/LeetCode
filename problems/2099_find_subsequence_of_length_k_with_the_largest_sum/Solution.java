import java.util.*;

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int[][] indexed = new int[nums.length][2];
        for (int i = 0; i < nums.length; i++) { indexed[i][0] = i; indexed[i][1] = nums[i]; }
        Arrays.sort(indexed, (a, b) -> b[1] - a[1]);
        int[][] top = Arrays.copyOfRange(indexed, 0, k);
        Arrays.sort(top, (a, b) -> a[0] - b[0]);
        int[] result = new int[k];
        for (int i = 0; i < k; i++) result[i] = top[i][1];
        return result;
    }
}
