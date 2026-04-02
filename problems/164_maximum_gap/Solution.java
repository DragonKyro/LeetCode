import java.util.*;

class Solution {
    public int maximumGap(int[] nums) {
        if (nums.length < 2) return 0;
        int lo = Integer.MAX_VALUE, hi = Integer.MIN_VALUE;
        for (int n : nums) { lo = Math.min(lo, n); hi = Math.max(hi, n); }
        if (lo == hi) return 0;
        int n = nums.length;
        int bucketSize = Math.max(1, (hi - lo) / (n - 1));
        int bucketCount = (hi - lo) / bucketSize + 1;
        int[] bMin = new int[bucketCount], bMax = new int[bucketCount];
        Arrays.fill(bMin, Integer.MAX_VALUE);
        Arrays.fill(bMax, Integer.MIN_VALUE);
        for (int num : nums) {
            int idx = (num - lo) / bucketSize;
            bMin[idx] = Math.min(bMin[idx], num);
            bMax[idx] = Math.max(bMax[idx], num);
        }
        int res = 0, prevMax = bMax[0];
        for (int i = 1; i < bucketCount; i++) {
            if (bMin[i] == Integer.MAX_VALUE) continue;
            res = Math.max(res, bMin[i] - prevMax);
            prevMax = bMax[i];
        }
        return res;
    }
}
