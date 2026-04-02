class Solution {
    public boolean judgeSquareSum(int c) {
        long a = 0;
        while (a * a <= c) {
            double b = Math.sqrt(c - a * a);
            if (b == (long) b) return true;
            a++;
        }
        return false;
    }
}
