class Solution {
    public int deleteAndEarn(int[] nums) {
        int max = 0;
        for (int n : nums) max = Math.max(max, n);
        int[] points = new int[max + 1];
        for (int n : nums) points[n] += n;
        int take = 0, skip = 0;
        for (int i = 1; i <= max; i++) {
            int newTake = skip + points[i];
            skip = Math.max(take, skip);
            take = newTake;
        }
        return Math.max(take, skip);
    }
}
