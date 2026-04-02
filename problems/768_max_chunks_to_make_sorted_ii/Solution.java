import java.util.*;

class Solution {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stack = new ArrayDeque<>();
        for (int num : arr) {
            int mx = num;
            while (!stack.isEmpty() && stack.peek() > num)
                mx = Math.max(mx, stack.pop());
            stack.push(mx);
        }
        return stack.size();
    }
}
