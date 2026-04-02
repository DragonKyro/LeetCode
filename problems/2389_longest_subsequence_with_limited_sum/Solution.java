import java.util.*;

class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) nums[i] += nums[i-1];
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int idx = Arrays.binarySearch(nums, queries[i]);
            result[i] = idx >= 0 ? idx + 1 : -idx - 1;
        }
        return result;
    }
}
