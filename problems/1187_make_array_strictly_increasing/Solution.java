import java.util.*;

class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        Arrays.sort(arr2);
        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(-1, 0);
        for (int num : arr1) {
            TreeMap<Integer, Integer> newDp = new TreeMap<>();
            for (var entry : dp.entrySet()) {
                int prev = entry.getKey(), ops = entry.getValue();
                if (num > prev) {
                    newDp.merge(num, ops, Math::min);
                }
                int idx = upperBound(arr2, prev);
                if (idx < arr2.length) {
                    newDp.merge(arr2[idx], ops + 1, Math::min);
                }
            }
            dp = newDp;
        }
        if (dp.isEmpty()) return -1;
        return Collections.min(dp.values());
    }
    private int upperBound(int[] arr, int val) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] <= val) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
