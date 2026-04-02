class Solution {
    public int minSwapsCouples(int[] row) {
        int[] pos = new int[row.length];
        for (int i = 0; i < row.length; i++) pos[row[i]] = i;
        int swaps = 0;
        for (int i = 0; i < row.length; i += 2) {
            int partner = row[i] ^ 1;
            if (row[i+1] != partner) {
                int j = pos[partner];
                pos[row[i+1]] = j;
                pos[partner] = i + 1;
                int tmp = row[i+1]; row[i+1] = row[j]; row[j] = tmp;
                swaps++;
            }
        }
        return swaps;
    }
}
