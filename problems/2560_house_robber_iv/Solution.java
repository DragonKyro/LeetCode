class Solution {
    public int minCapability(int[] nums, int k) {
        int lo = Integer.MAX_VALUE, hi = 0;
        for (int n : nums) { lo = Math.min(lo, n); hi = Math.max(hi, n); }
        while (lo < hi) {
            int mid = (lo+hi)/2, count = 0;
            for (int i = 0; i < nums.length; ) {
                if (nums[i] <= mid) { count++; i += 2; } else i++;
            }
            if (count >= k) hi = mid; else lo = mid+1;
        }
        return lo;
    }
}
