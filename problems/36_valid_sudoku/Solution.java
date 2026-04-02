import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> seen = new HashSet<>();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (!seen.add(c + "r" + i) || !seen.add(c + "c" + j) || !seen.add(c + "b" + i/3 + j/3))
                    return false;
            }
        }
        return true;
    }
}
