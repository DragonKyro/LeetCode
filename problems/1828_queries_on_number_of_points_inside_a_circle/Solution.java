class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int xc = queries[i][0], yc = queries[i][1], r = queries[i][2];
            for (int[] p : points) {
                if ((p[0] - xc) * (p[0] - xc) + (p[1] - yc) * (p[1] - yc) <= r * r) {
                    result[i]++;
                }
            }
        }
        return result;
    }
}
