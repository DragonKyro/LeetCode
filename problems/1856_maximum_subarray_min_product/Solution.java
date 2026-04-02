import java.util.*;

class Solution {
    public int maxSumMinProduct(int[] nums) {
        long MOD = 1000000007;
        int n = nums.length;
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        int[] left = new int[n], right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] >= nums[i]) right[stack.pop()] = i;
            if (!stack.isEmpty()) left[i] = stack.peek();
            stack.push(i);
        }
        long result = 0;
        for (int i = 0; i < n; i++) {
            long total = prefix[right[i]] - prefix[left[i] + 1];
            result = Math.max(result, (long) nums[i] * total);
        }
        return (int) (result % MOD);
    }
}
