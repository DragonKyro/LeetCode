class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        if (dist.length - 1 >= hour) return -1;
        int lo = 1, hi = 10000000;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            double total = 0;
            for (int i = 0; i < dist.length - 1; i++) total += Math.ceil((double) dist[i] / mid);
            total += (double) dist[dist.length - 1] / mid;
            if (total <= hour) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
