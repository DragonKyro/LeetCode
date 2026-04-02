import java.util.*;

class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        Map<Integer, Integer> rank = new HashMap<>();
        for (int i = 0; i < sorted.length; i++) rank.putIfAbsent(sorted[i], i);
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) res[i] = rank.get(nums[i]);
        return res;
    }
}
