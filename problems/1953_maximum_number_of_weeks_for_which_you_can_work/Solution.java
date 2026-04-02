class Solution {
    public long numberOfWeeks(int[] milestones) {
        long total = 0, maxVal = 0;
        for (int m : milestones) { total += m; maxVal = Math.max(maxVal, m); }
        long rest = total - maxVal;
        return maxVal > rest + 1 ? 2 * rest + 1 : total;
    }
}
