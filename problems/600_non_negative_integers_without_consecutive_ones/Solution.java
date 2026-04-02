class Solution {
    public int findIntegers(int n) {
        String bits = Integer.toBinaryString(n);
        int len = bits.length();
        int[] fib = new int[len + 2];
        fib[0] = 1; fib[1] = 2;
        for (int i = 2; i <= len; i++) fib[i] = fib[i-1] + fib[i-2];
        int result = 0, prevBit = 0;
        for (int i = 0; i < len; i++) {
            if (bits.charAt(i) == '1') {
                result += fib[len - 1 - i];
                if (prevBit == 1) return result;
                prevBit = 1;
            } else {
                prevBit = 0;
            }
        }
        return result + 1;
    }
}
