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
    string tictactoe(vector<vector<int>>& moves) {
        int board[3][3] = {};
        for (int i = 0; i < (int)moves.size(); i++)
            board[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 1 : 2;
        for (int p = 1; p <= 2; p++) {
            for (int i = 0; i < 3; i++) {
                if (board[i][0]==p && board[i][1]==p && board[i][2]==p) return p==1?"A":"B";
                if (board[0][i]==p && board[1][i]==p && board[2][i]==p) return p==1?"A":"B";
            }
            if (board[0][0]==p && board[1][1]==p && board[2][2]==p) return p==1?"A":"B";
            if (board[0][2]==p && board[1][1]==p && board[2][0]==p) return p==1?"A":"B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
