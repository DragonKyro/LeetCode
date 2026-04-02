class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int evenSum = 0;
        for (int n : nums) if (n % 2 == 0) evenSum += n;
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int val = queries[i][0], idx = queries[i][1];
            if (nums[idx] % 2 == 0) evenSum -= nums[idx];
            nums[idx] += val;
            if (nums[idx] % 2 == 0) evenSum += nums[idx];
            result[i] = evenSum;
        }
        return result;
    }
}
