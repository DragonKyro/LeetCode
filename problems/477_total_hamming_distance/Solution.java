class Solution {
    public int totalHammingDistance(int[] nums) {
        int total = 0, n = nums.length;
        for (int bit = 0; bit < 32; bit++) {
            int ones = 0;
            for (int num : nums) if ((num & (1 << bit)) != 0) ones++;
            total += ones * (n - ones);
        }
        return total;
    }
}
