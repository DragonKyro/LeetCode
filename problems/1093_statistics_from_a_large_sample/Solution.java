class Solution {
    public double[] sampleStats(int[] count) {
        int min = -1, max = -1, mode = 0;
        long total = 0, n = 0;
        int maxCount = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                if (min == -1) min = i;
                max = i;
                total += (long)i * count[i];
                n += count[i];
                if (count[i] > maxCount) { maxCount = count[i]; mode = i; }
            }
        }
        double mean = (double)total / n;
        long mid1 = (n - 1) / 2, mid2 = n / 2;
        int m1 = 0, m2 = 0;
        long cumul = 0;
        for (int i = 0; i < 256; i++) {
            cumul += count[i];
            if (m1 == 0 && cumul > mid1) m1 = i;
            if (m2 == 0 && cumul > mid2) m2 = i;
        }
        double median = (m1 + m2) / 2.0;
        return new double[]{min, max, mean, median, mode};
    }
}
