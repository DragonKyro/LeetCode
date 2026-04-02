class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        for (int[] row : image) {
            int n = row.length;
            for (int i = 0; i < (n + 1) / 2; i++) {
                int tmp = row[i] ^ 1;
                row[i] = row[n - 1 - i] ^ 1;
                row[n - 1 - i] = tmp;
            }
        }
        return image;
    }
}
