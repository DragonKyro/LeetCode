class Solution {
    public int addRungs(int[] rungs, int dist) {
        int result = 0, prev = 0;
        for (int r : rungs) {
            result += (r - prev - 1) / dist;
            prev = r;
        }
        return result;
    }
}
