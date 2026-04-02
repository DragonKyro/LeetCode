import java.util.*;

class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int fuel = startFuel, stops = 0, prev = 0;
        for (int i = 0; i <= stations.length; i++) {
            int pos = i < stations.length ? stations[i][0] : target;
            fuel -= pos - prev;
            while (!pq.isEmpty() && fuel < 0) { fuel += pq.poll(); stops++; }
            if (fuel < 0) return -1;
            if (i < stations.length) pq.add(stations[i][1]);
            prev = pos;
        }
        return stops;
    }
}
