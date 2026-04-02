class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length, g = 0;
        for (int x : nums) g = gcd(g, x);
        if (g > 1) return -1;
        int ans = n - 1;
        for (int i = 0; i < n; i++) {
            int gg = nums[i];
            for (int j = i+1; j < n; j++) {
                gg = gcd(gg, nums[j]);
                if (gg == 1) { ans = Math.min(ans, j-i+n-2); break; }
            }
        }
        return ans;
    }
    int gcd(int a, int b) { return b==0?a:gcd(b,a%b); }
}
