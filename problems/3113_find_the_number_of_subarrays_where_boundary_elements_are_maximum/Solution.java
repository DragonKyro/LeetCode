import java.util.*;

class Solution {
    public long numberOfSubarrays(int[] nums) {
        long res = 0;
        Deque<long[]> stack = new ArrayDeque<>();
        for (int x : nums) {
            while (!stack.isEmpty() && stack.peek()[0] < x) stack.pop();
            if (!stack.isEmpty() && stack.peek()[0] == x) {
                stack.peek()[1]++;
                res += stack.peek()[1];
            } else {
                stack.push(new long[]{x, 1});
                res++;
            }
        }
        return res;
    }
}
