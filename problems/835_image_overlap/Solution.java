import java.util.*;

class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        List<int[]> pts1 = new ArrayList<>(), pts2 = new ArrayList<>();
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            if (img1[r][c] == 1) pts1.add(new int[]{r, c});
            if (img2[r][c] == 1) pts2.add(new int[]{r, c});
        }
        Map<Integer, Integer> count = new HashMap<>();
        int result = 0;
        for (int[] p1 : pts1) for (int[] p2 : pts2) {
            int key = (p1[0]-p2[0]+30) * 100 + (p1[1]-p2[1]+30);
            int val = count.merge(key, 1, Integer::sum);
            result = Math.max(result, val);
        }
        return result;
    }
}
