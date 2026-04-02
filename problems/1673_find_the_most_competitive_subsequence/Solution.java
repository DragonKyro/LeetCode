import java.util.*;

class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Deque<Integer> stack = new ArrayDeque<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && stack.peek() > nums[i] && stack.size() + (n - i) > k) {
                stack.pop();
            }
            if (stack.size() < k) stack.push(nums[i]);
        }
        int[] result = new int[k];
        for (int i = k - 1; i >= 0; i--) result[i] = stack.pop();
        return result;
    }
}
