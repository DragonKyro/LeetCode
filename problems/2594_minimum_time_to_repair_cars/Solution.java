class Solution {
    public long repairCars(int[] ranks, int cars) {
        long lo = 1, hi = (long) ranks[0] * cars * cars;
        for (int r : ranks) hi = Math.min(hi, (long) r * cars * cars);
        while (lo < hi) {
            long mid = (lo+hi)/2, total = 0;
            for (int r : ranks) total += (long) Math.sqrt(mid / (double) r);
            if (total >= cars) hi = mid; else lo = mid+1;
        }
        return lo;
    }
}
