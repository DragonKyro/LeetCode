import java.util.*;

class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        boolean[] visited = new boolean[n];
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(start);
        while (!stack.isEmpty()) {
            int i = stack.pop();
            if (arr[i] == 0) return true;
            if (visited[i]) continue;
            visited[i] = true;
            if (i + arr[i] < n) stack.push(i + arr[i]);
            if (i - arr[i] >= 0) stack.push(i - arr[i]);
        }
        return false;
    }
}
