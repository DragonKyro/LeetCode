class Solution {
    public int findMinMoves(int[] machines) {
        int total = 0;
        for (int m : machines) total += m;
        int n = machines.length;
        if (total % n != 0) return -1;
        int avg = total / n, res = 0, runningSum = 0;
        for (int m : machines) {
            int diff = m - avg;
            runningSum += diff;
            res = Math.max(res, Math.max(Math.abs(runningSum), diff));
        }
        return res;
    }
}
