import java.util.*;

class Solution {
    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        long MOD = 1000000007;
        int n = nums1.length;
        int[] sorted = nums1.clone();
        Arrays.sort(sorted);
        long total = 0;
        for (int i = 0; i < n; i++) total += Math.abs(nums1[i] - nums2[i]);
        long maxImprove = 0;
        for (int i = 0; i < n; i++) {
            int curr = Math.abs(nums1[i] - nums2[i]);
            int idx = Arrays.binarySearch(sorted, nums2[i]);
            if (idx < 0) idx = -idx - 1;
            if (idx < n) maxImprove = Math.max(maxImprove, curr - Math.abs(sorted[idx] - nums2[i]));
            if (idx > 0) maxImprove = Math.max(maxImprove, curr - Math.abs(sorted[idx - 1] - nums2[i]));
        }
        return (int) ((total - maxImprove) % MOD);
    }
}
