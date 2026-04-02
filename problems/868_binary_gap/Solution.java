class Solution {
    public int binaryGap(int n) {
        int last = -1, result = 0;
        for (int i = 0; n > 0; i++, n >>= 1) {
            if ((n & 1) == 1) {
                if (last >= 0) result = Math.max(result, i - last);
                last = i;
            }
        }
        return result;
    }
}
