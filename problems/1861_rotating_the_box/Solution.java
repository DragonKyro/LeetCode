class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length, n = box[0].length;
        for (int i = 0; i < m; i++) {
            int empty = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') empty = j - 1;
                else if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[i][empty] = '#';
                    empty--;
                }
            }
        }
        char[][] result = new char[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result[i][j] = box[m - 1 - j][i];
        return result;
    }
}
