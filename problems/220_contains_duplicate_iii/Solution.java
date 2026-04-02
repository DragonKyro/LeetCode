import java.util.*;

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;
        Map<Long, Long> buckets = new HashMap<>();
        long w = (long) valueDiff + 1;
        for (int i = 0; i < nums.length; i++) {
            long bucket = Math.floorDiv((long) nums[i], w);
            if (buckets.containsKey(bucket)) return true;
            if (buckets.containsKey(bucket - 1) && Math.abs(nums[i] - buckets.get(bucket - 1)) < w) return true;
            if (buckets.containsKey(bucket + 1) && Math.abs(nums[i] - buckets.get(bucket + 1)) < w) return true;
            buckets.put(bucket, (long) nums[i]);
            if (i >= indexDiff) buckets.remove(Math.floorDiv((long) nums[i - indexDiff], w));
        }
        return false;
    }
}
