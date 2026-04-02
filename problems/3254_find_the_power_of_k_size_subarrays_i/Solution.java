class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length, cnt = 1;
        int[] res = new int[n-k+1];
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]+1) cnt++;
            else cnt = 1;
            if (i >= k-1) res[i-k+1] = cnt >= k ? nums[i] : -1;
        }
        return res;
    }
}
