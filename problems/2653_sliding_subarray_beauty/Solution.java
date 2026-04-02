class Solution {
    public int[] getSubarrayBeauty(int[] nums, int k, int x) {
        int[] cnt = new int[101];
        int n = nums.length;
        int[] ans = new int[n-k+1];
        for (int i = 0; i < n; i++) {
            cnt[nums[i]+50]++;
            if (i >= k) cnt[nums[i-k]+50]--;
            if (i >= k-1) {
                int c = 0;
                for (int j = 0; j < 101; j++) {
                    c += cnt[j];
                    if (c >= x) { ans[i-k+1] = j-50 < 0 ? j-50 : 0; break; }
                }
            }
        }
        return ans;
    }
}
