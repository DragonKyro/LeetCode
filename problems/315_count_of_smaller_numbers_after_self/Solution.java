import java.util.*;

class Solution {
    int[] res, idx, temp, tempIdx;
    int[] nums;
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        res = new int[n];
        idx = new int[n];
        temp = new int[n];
        tempIdx = new int[n];
        for (int i = 0; i < n; i++) idx[i] = i;
        mergeSort(0, n - 1);
        List<Integer> list = new ArrayList<>();
        for (int r : res) list.add(r);
        return list;
    }
    void mergeSort(int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(lo, mid);
        mergeSort(mid + 1, hi);
        int i = lo, j = mid + 1, k = lo;
        while (i <= mid && j <= hi) {
            if (nums[idx[i]] <= nums[idx[j]]) {
                res[idx[i]] += j - mid - 1;
                tempIdx[k++] = idx[i++];
            } else {
                tempIdx[k++] = idx[j++];
            }
        }
        while (i <= mid) {
            res[idx[i]] += j - mid - 1;
            tempIdx[k++] = idx[i++];
        }
        while (j <= hi) tempIdx[k++] = idx[j++];
        for (int p = lo; p <= hi; p++) idx[p] = tempIdx[p];
    }
}
