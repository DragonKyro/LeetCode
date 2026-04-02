import java.util.*;

class Solution {
    public int slidingPuzzle(int[][] board) {
        String target = "123450";
        StringBuilder sb = new StringBuilder();
        for (int[] row : board) for (int v : row) sb.append(v);
        String start = sb.toString();
        if (start.equals(target)) return 0;
        int[][] moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer(start); visited.add(start);
        int step = 0;
        while (!queue.isEmpty()) {
            step++;
            int size = queue.size();
            for (int s = 0; s < size; s++) {
                String state = queue.poll();
                int idx = state.indexOf('0');
                for (int nei : moves[idx]) {
                    char[] arr = state.toCharArray();
                    arr[idx] = arr[nei]; arr[nei] = '0';
                    String next = new String(arr);
                    if (next.equals(target)) return step;
                    if (visited.add(next)) queue.offer(next);
                }
            }
        }
        return -1;
    }
}
