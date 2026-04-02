class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        double lo = 0, hi = 1;
        while (lo < hi) {
            double mid = (lo + hi) / 2;
            int count = 0, p = 0, q = 1;
            int j = 1;
            for (int i = 0; i < n; i++) {
                while (j < n && (double)arr[i] / arr[j] > mid) j++;
                count += n - j;
                if (j < n && (long)arr[i] * q > (long)p * arr[j]) {
                    p = arr[i]; q = arr[j];
                }
            }
            if (count == k) return new int[]{p, q};
            else if (count < k) lo = mid;
            else hi = mid;
        }
        return new int[]{};
    }
}
