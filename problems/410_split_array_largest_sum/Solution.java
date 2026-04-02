class Solution {
    public int splitArray(int[] nums, int k) {
        long left = 0, right = 0;
        for (int num : nums) {
            left = Math.max(left, num);
            right += num;
        }
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) right = mid;
            else left = mid + 1;
        }
        return (int) left;
    }

    private boolean canSplit(int[] nums, int k, long largest) {
        int pieces = 1;
        long sum = 0;
        for (int num : nums) {
            if (sum + num > largest) {
                pieces++;
                sum = num;
                if (pieces > k) return false;
            } else {
                sum += num;
            }
        }
        return true;
    }
}
