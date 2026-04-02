import java.util.*;

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxD = new ArrayDeque<>(), minD = new ArrayDeque<>();
        int left = 0, res = 0;
        for (int right = 0; right < nums.length; right++) {
            while (!maxD.isEmpty() && nums[right] > maxD.peekLast()) maxD.pollLast();
            while (!minD.isEmpty() && nums[right] < minD.peekLast()) minD.pollLast();
            maxD.addLast(nums[right]);
            minD.addLast(nums[right]);
            while (maxD.peekFirst() - minD.peekFirst() > limit) {
                if (nums[left] == maxD.peekFirst()) maxD.pollFirst();
                if (nums[left] == minD.peekFirst()) minD.pollFirst();
                left++;
            }
            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}
