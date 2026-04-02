class Solution {
    public int bestRotation(int[] nums) {
        int n = nums.length;
        int[] change = new int[n];
        for (int i = 0; i < n; i++) {
            int lo = (i + 1) % n;
            int hi = (i - nums[i] + n) % n;
            if (lo <= hi) {
                change[lo]++;
                if (hi + 1 < n) change[hi + 1]--;
            } else {
                change[0]++;
                if (hi + 1 < n) change[hi + 1]--;
                change[lo]++;
            }
        }
        int best = -1, bestK = 0, cur = 0;
        for (int k = 0; k < n; k++) {
            cur += change[k];
            if (cur > best) { best = cur; bestK = k; }
        }
        return bestK;
    }
}
