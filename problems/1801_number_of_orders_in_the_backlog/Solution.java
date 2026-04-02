import java.util.*;

class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        long MOD = 1000000007;
        PriorityQueue<long[]> buy = new PriorityQueue<>((a, b) -> Long.compare(b[0], a[0]));
        PriorityQueue<long[]> sell = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        for (int[] order : orders) {
            if (order[2] == 0) {
                buy.offer(new long[]{order[0], order[1]});
            } else {
                sell.offer(new long[]{order[0], order[1]});
            }
            while (!buy.isEmpty() && !sell.isEmpty() && buy.peek()[0] >= sell.peek()[0]) {
                long[] b = buy.poll();
                long[] s = sell.poll();
                long matched = Math.min(b[1], s[1]);
                if (b[1] - matched > 0) buy.offer(new long[]{b[0], b[1] - matched});
                if (s[1] - matched > 0) sell.offer(new long[]{s[0], s[1] - matched});
            }
        }
        long total = 0;
        for (long[] b : buy) total = (total + b[1]) % MOD;
        for (long[] s : sell) total = (total + s[1]) % MOD;
        return (int) total;
    }
}
