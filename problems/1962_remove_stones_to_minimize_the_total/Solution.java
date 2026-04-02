import java.util.*;

class Solution {
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int p : piles) pq.offer(p);
        for (int i = 0; i < k; i++) {
            int top = pq.poll();
            pq.offer(top - top / 2);
        }
        int sum = 0;
        for (int p : pq) sum += p;
        return sum;
    }
}
