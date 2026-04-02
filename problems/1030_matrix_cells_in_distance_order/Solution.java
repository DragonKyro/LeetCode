import java.util.*;

class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int[][] cells = new int[rows * cols][2];
        int idx = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cells[idx++] = new int[]{i, j};
        Arrays.sort(cells, (a, b) -> Math.abs(a[0]-rCenter)+Math.abs(a[1]-cCenter) - Math.abs(b[0]-rCenter)-Math.abs(b[1]-cCenter));
        return cells;
    }
}
