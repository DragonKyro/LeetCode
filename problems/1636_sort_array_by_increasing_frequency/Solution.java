import java.util.*;

class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) count.merge(num, 1, Integer::sum);
        Integer[] arr = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) arr[i] = nums[i];
        Arrays.sort(arr, (a, b) -> count.get(a) != count.get(b) ? count.get(a) - count.get(b) : b - a);
        for (int i = 0; i < nums.length; i++) nums[i] = arr[i];
        return nums;
    }
}
