class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        return mergeSort(prefix, 0, n, lower, upper);
    }
    private int mergeSort(long[] prefix, int lo, int hi, int lower, int upper) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int count = mergeSort(prefix, lo, mid, lower, upper) + mergeSort(prefix, mid + 1, hi, lower, upper);
        int j1 = mid + 1, j2 = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (j1 <= hi && prefix[j1] - prefix[i] < lower) j1++;
            while (j2 <= hi && prefix[j2] - prefix[i] <= upper) j2++;
            count += j2 - j1;
        }
        long[] merged = new long[hi - lo + 1];
        int i = lo, j = mid + 1, k = 0;
        while (i <= mid && j <= hi) {
            if (prefix[i] <= prefix[j]) merged[k++] = prefix[i++];
            else merged[k++] = prefix[j++];
        }
        while (i <= mid) merged[k++] = prefix[i++];
        while (j <= hi) merged[k++] = prefix[j++];
        System.arraycopy(merged, 0, prefix, lo, merged.length);
        return count;
    }
}
