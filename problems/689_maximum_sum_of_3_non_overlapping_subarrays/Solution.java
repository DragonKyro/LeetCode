class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] sums = new int[n - k + 1];
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            if (i >= k) s -= nums[i - k];
            if (i >= k - 1) sums[i - k + 1] = s;
        }
        int[] left = new int[sums.length];
        int best = 0;
        for (int i = 0; i < sums.length; i++) {
            if (sums[i] > sums[best]) best = i;
            left[i] = best;
        }
        int[] right = new int[sums.length];
        best = sums.length - 1;
        for (int i = sums.length - 1; i >= 0; i--) {
            if (sums[i] >= sums[best]) best = i;
            right[i] = best;
        }
        int[] result = new int[3];
        int maxSum = 0;
        for (int j = k; j < sums.length - k; j++) {
            int li = left[j - k], ri = right[j + k];
            int total = sums[li] + sums[j] + sums[ri];
            if (total > maxSum) {
                maxSum = total;
                result = new int[]{li, j, ri};
            }
        }
        return result;
    }
}
