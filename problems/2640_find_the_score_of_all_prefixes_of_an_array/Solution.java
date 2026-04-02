class Solution {
    public long[] findPrefixScore(int[] nums) {
        long[] ans = new long[nums.length];
        long mx = 0, s = 0;
        for (int i = 0; i < nums.length; i++) {
            mx = Math.max(mx, nums[i]);
            s += nums[i] + mx;
            ans[i] = s;
        }
        return ans;
    }
}
