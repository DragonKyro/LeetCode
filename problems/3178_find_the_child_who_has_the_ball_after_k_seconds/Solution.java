class Solution {
    public int numberOfChild(int n, int k) {
        int cycle = 2 * (n - 1);
        k %= cycle;
        return k < n ? k : cycle - k;
    }
}
