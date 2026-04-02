class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, unique = 9, avail = 9;
        for (int i = 2; i <= Math.min(n, 10); i++) {
            unique *= avail;
            res += unique;
            avail--;
        }
        return res;
    }
}
