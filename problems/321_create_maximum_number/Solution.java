class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] best = new int[k];
        for (int i = Math.max(0, k - nums2.length); i <= Math.min(k, nums1.length); i++) {
            int[] a = maxSingle(nums1, i);
            int[] b = maxSingle(nums2, k - i);
            int[] candidate = merge(a, b);
            if (compare(candidate, 0, best, 0) > 0) best = candidate;
        }
        return best;
    }
    int[] maxSingle(int[] nums, int t) {
        int[] stack = new int[t];
        int drop = nums.length - t, top = -1;
        for (int num : nums) {
            while (top >= 0 && drop > 0 && stack[top] < num) { top--; drop--; }
            if (top + 1 < t) stack[++top] = num;
            else drop--;
        }
        return stack;
    }
    int[] merge(int[] a, int[] b) {
        int[] res = new int[a.length + b.length];
        int i = 0, j = 0, k = 0;
        while (i < a.length && j < b.length) {
            if (compare(a, i, b, j) >= 0) res[k++] = a[i++];
            else res[k++] = b[j++];
        }
        while (i < a.length) res[k++] = a[i++];
        while (j < b.length) res[k++] = b[j++];
        return res;
    }
    int compare(int[] a, int i, int[] b, int j) {
        while (i < a.length && j < b.length) {
            if (a[i] != b[j]) return a[i] - b[j];
            i++; j++;
        }
        return (a.length - i) - (b.length - j);
    }
}
