import java.util.*;

class Solution {
    public int findBestValue(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
        int ans = 0, minDiff = Integer.MAX_VALUE;
        for (int v = 0; v <= arr[n-1]; v++) {
            int idx = upperBound(arr, v);
            int total = prefix[idx] + v * (n - idx);
            int diff = Math.abs(total - target);
            if (diff < minDiff) { minDiff = diff; ans = v; }
        }
        return ans;
    }
    int upperBound(int[] arr, int val) {
        int lo = 0, hi = arr.length;
        while (lo < hi) { int mid = (lo+hi)/2; if (arr[mid] <= val) lo = mid+1; else hi = mid; }
        return lo;
    }
}
