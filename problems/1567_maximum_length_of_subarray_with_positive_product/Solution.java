class Solution {
    public int getMaxLen(int[] nums) {
        int pos = 0, neg = 0, res = 0;
        for (int n : nums) {
            if (n > 0) {
                pos++;
                neg = neg > 0 ? neg + 1 : 0;
            } else if (n < 0) {
                int newPos = neg > 0 ? neg + 1 : 0;
                neg = pos + 1;
                pos = newPos;
            } else {
                pos = neg = 0;
            }
            res = Math.max(res, pos);
        }
        return res;
    }
}
