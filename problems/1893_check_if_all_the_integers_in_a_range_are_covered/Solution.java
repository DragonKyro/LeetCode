class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        for (int i = left; i <= right; i++) {
            boolean covered = false;
            for (int[] r : ranges) {
                if (r[0] <= i && i <= r[1]) { covered = true; break; }
            }
            if (!covered) return false;
        }
        return true;
    }
}
