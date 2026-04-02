class Solution {
    public int reinitializePermutation(int n) {
        int[] perm = new int[n];
        for (int i = 0; i < n; i++) perm[i] = i;
        int ops = 0;
        do {
            ops++;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = (i % 2 == 0) ? perm[i / 2] : perm[n / 2 + (i - 1) / 2];
            }
            perm = arr;
        } while (!check(perm, n));
        return ops;
    }
    private boolean check(int[] perm, int n) {
        for (int i = 0; i < n; i++) if (perm[i] != i) return false;
        return true;
    }
}
