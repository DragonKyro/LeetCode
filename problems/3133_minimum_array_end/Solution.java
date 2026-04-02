class Solution {
    public long minEnd(int n, int x) {
        long res = x;
        n--;
        int bit = 0;
        for (int i = 0; i < 63; i++) {
            if (((x >> i) & 1) == 0) {
                if (((n >> bit) & 1) == 1) res |= 1L << i;
                bit++;
            }
        }
        return res;
    }
}
