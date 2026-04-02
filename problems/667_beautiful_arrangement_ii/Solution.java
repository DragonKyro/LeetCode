class Solution {
    public int[] constructArray(int n, int k) {
        int[] result = new int[n];
        for (int i = 0; i < n - k - 1; i++) result[i] = i + 1;
        for (int i = 0; i <= k; i++) {
            if (i % 2 == 0) result[n - k - 1 + i] = n - k + i / 2;
            else result[n - k - 1 + i] = n - i / 2;
        }
        return result;
    }
}
