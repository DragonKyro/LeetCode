import java.util.*;

class Solution {
    public int medianOfUniquenessArray(int[] nums) {
        int n = nums.length;
        long total = (long)n * (n + 1) / 2;
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (atMost(nums, mid) >= (total + 1) / 2) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    long atMost(int[] nums, int k) {
        long count = 0;
        Map<Integer,Integer> freq = new HashMap<>();
        int l = 0;
        for (int r = 0; r < nums.length; r++) {
            freq.merge(nums[r], 1, Integer::sum);
            while (freq.size() > k) {
                freq.merge(nums[l], -1, Integer::sum);
                if (freq.get(nums[l]) == 0) freq.remove(nums[l]);
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
}
