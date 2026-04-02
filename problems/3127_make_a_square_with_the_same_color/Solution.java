class Solution {
    public boolean canMakeSquare(char[][] grid) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                int b = 0;
                for (int di = 0; di < 2; di++)
                    for (int dj = 0; dj < 2; dj++)
                        if (grid[i+di][j+dj] == 'B') b++;
                if (b >= 3 || b <= 1) return true;
            }
        return false;
    }
}
