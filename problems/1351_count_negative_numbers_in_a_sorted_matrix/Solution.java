class Solution {
    public int countNegatives(int[][] grid) {
        int count = 0;
        for (int[] row : grid)
            for (int x : row)
                if (x < 0) count++;
        return count;
    }
}
