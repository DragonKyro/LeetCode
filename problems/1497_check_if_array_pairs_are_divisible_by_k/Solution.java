class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] remainder = new int[k];
        for (int n : arr) remainder[((n % k) + k) % k]++;
        if (remainder[0] % 2 != 0) return false;
        for (int i = 1; i <= k / 2; i++) {
            if (i == k - i) { if (remainder[i] % 2 != 0) return false; }
            else { if (remainder[i] != remainder[k - i]) return false; }
        }
        return true;
    }
}
