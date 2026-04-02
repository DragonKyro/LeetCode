class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int notSwap = 0, swap = 1;
        for (int i = 1; i < n; i++) {
            int newNotSwap = Integer.MAX_VALUE, newSwap = Integer.MAX_VALUE;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                newNotSwap = notSwap;
                newSwap = swap + 1;
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                newNotSwap = Math.min(newNotSwap, swap);
                newSwap = Math.min(newSwap, notSwap + 1);
            }
            notSwap = newNotSwap;
            swap = newSwap;
        }
        return Math.min(notSwap, swap);
    }
}
