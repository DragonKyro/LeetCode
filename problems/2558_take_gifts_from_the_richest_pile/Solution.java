import java.util.*;

class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int g : gifts) pq.offer(g);
        for (int i = 0; i < k; i++) pq.offer((int)Math.sqrt(pq.poll()));
        long sum = 0;
        for (int g : pq) sum += g;
        return sum;
    }
}
