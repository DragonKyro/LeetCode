class Solution {
    public int alternatingSubarray(int[] nums) {
        int ans = -1, n = nums.length;
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1]-nums[i] == 1) {
                int j = i+1, exp = -1;
                while (j+1<n && nums[j+1]-nums[j]==exp) { j++; exp *= -1; }
                ans = Math.max(ans, j-i+1);
            }
        }
        return ans;
    }
}
