class Solution {
    public int rob(int[] nums) {
        int prev = 0, curr = 0;
        for (int num : nums) {
            int tmp = curr;
            curr = Math.max(curr, prev + num);
            prev = tmp;
        }
        return curr;
    }
}
