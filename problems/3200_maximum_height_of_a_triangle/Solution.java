class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(check(red, blue), check(blue, red));
    }
    int check(int a, int b) {
        int row = 1;
        while (true) {
            if (row % 2 == 1) { a -= row; if (a < 0) return row-1; }
            else { b -= row; if (b < 0) return row-1; }
            row++;
        }
    }
}
