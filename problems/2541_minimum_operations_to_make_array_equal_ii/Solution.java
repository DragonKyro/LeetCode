class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        if (k == 0) {
            for (int i = 0; i < nums1.length; i++) if (nums1[i] != nums2[i]) return -1;
            return 0;
        }
        long pos = 0, neg = 0;
        for (int i = 0; i < nums1.length; i++) {
            long diff = nums1[i] - nums2[i];
            if (diff % k != 0) return -1;
            if (diff > 0) pos += diff / k; else neg += -diff / k;
        }
        return pos == neg ? pos : -1;
    }
}
