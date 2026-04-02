import java.util.*;

class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int n : nums) pq.offer(n);
        long score = 0;
        for (int i = 0; i < k; i++) {
            int val = pq.poll();
            score += val;
            pq.offer((val + 2) / 3);
        }
        return score;
    }
}
