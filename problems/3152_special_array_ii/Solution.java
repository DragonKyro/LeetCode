class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] prefix = new int[n];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + (nums[i]%2 == nums[i-1]%2 ? 1 : 0);
        boolean[] res = new boolean[queries.length];
        for (int i = 0; i < queries.length; i++)
            res[i] = prefix[queries[i][1]] - prefix[queries[i][0]] == 0;
        return res;
    }
}
