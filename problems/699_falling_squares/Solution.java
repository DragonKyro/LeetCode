import java.util.*;

class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        List<int[]> intervals = new ArrayList<>();
        List<Integer> result = new ArrayList<>();
        int maxHeight = 0;
        for (int[] pos : positions) {
            int left = pos[0], side = pos[1], right = left + side;
            int height = side;
            for (int[] iv : intervals) {
                if (iv[0] < right && left < iv[1]) {
                    height = Math.max(height, iv[2] + side);
                }
            }
            intervals.add(new int[]{left, right, height});
            maxHeight = Math.max(maxHeight, height);
            result.add(maxHeight);
        }
        return result;
    }
}
