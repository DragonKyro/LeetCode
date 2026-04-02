class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long a = Math.abs((long)dividend), b = Math.abs((long)divisor);
        int res = 0;
        while (a >= b) {
            long temp = b;
            int m = 1;
            while (a >= (temp << 1)) { temp <<= 1; m <<= 1; }
            a -= temp;
            res += m;
        }
        return sign * res;
    }
}
