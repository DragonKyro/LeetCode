class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        int step = 0, total = 0;
        while (total < target || (total - target) % 2 != 0) {
            step++;
            total += step;
        }
        return step;
    }
}
