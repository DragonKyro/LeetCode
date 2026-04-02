class Solution {
    public long sumDigitDifferences(int[] nums) {
        int n = nums.length, d = String.valueOf(nums[0]).length();
        long res = 0;
        for (int pos = 0; pos < d; pos++) {
            int[] cnt = new int[10];
            for (int x : nums) cnt[(x / (int)Math.pow(10, pos)) % 10]++;
            for (int c : cnt) res += (long)c * (n - c);
        }
        return res / 2;
    }
}
