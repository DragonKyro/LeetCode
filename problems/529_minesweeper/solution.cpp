#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') { board[r][c] = 'X'; return board; }
        int m = board.size(), n = board[0].size();
        function<void(int, int)> dfs = [&](int i, int j) {
            int mines = 0;
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'M') mines++;
                }
            if (mines > 0) { board[i][j] = '0' + mines; return; }
            board[i][j] = 'B';
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'E') dfs(ni, nj);
                }
        };
        dfs(r, c);
        return board;
    }
};
