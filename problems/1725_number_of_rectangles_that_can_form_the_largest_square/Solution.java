class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int maxSide = 0, count = 0;
        for (int[] r : rectangles) {
            int side = Math.min(r[0], r[1]);
            if (side > maxSide) { maxSide = side; count = 1; }
            else if (side == maxSide) count++;
        }
        return count;
    }
}
