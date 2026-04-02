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
    bool validTicTacToe(vector<string>& board) {
        int xc = 0, oc = 0;
        for (auto& row : board) for (char c : row) { if (c=='X') xc++; if (c=='O') oc++; }
        if (oc > xc || xc > oc + 1) return false;
        if (wins(board, 'X') && oc != xc - 1) return false;
        if (wins(board, 'O') && xc != oc) return false;
        return true;
    }

    bool wins(vector<string>& board, char p) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0]==p && board[i][1]==p && board[i][2]==p) return true;
            if (board[0][i]==p && board[1][i]==p && board[2][i]==p) return true;
        }
        if (board[0][0]==p && board[1][1]==p && board[2][2]==p) return true;
        if (board[0][2]==p && board[1][1]==p && board[2][0]==p) return true;
        return false;
    }
};
