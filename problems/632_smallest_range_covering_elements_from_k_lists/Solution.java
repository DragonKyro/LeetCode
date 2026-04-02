import java.util.*;

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int maxVal = Integer.MIN_VALUE;
        for (int i = 0; i < nums.size(); i++) {
            pq.offer(new int[]{nums.get(i).get(0), i, 0});
            maxVal = Math.max(maxVal, nums.get(i).get(0));
        }
        int[] best = {0, Integer.MAX_VALUE};
        while (true) {
            int[] curr = pq.poll();
            int minVal = curr[0], i = curr[1], j = curr[2];
            if (maxVal - minVal < best[1] - best[0]) {
                best = new int[]{minVal, maxVal};
            }
            if (j + 1 >= nums.get(i).size()) break;
            int next = nums.get(i).get(j + 1);
            maxVal = Math.max(maxVal, next);
            pq.offer(new int[]{next, i, j + 1});
        }
        return best;
    }
}
