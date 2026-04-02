import java.util.*;

class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] ugly = new int[n];
        ugly[0] = 1;
        int[] idx = new int[primes.length];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < primes.length; i++)
            pq.offer(new int[]{primes[i], i});
        for (int i = 1; i < n; i++) {
            ugly[i] = pq.peek()[0];
            while (pq.peek()[0] == ugly[i]) {
                int[] top = pq.poll();
                int j = top[1];
                idx[j]++;
                pq.offer(new int[]{primes[j] * ugly[idx[j]], j});
            }
        }
        return ugly[n - 1];
    }
}
