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
    int numRookCaptures(vector<vector<char>>& board) {
        int rx = 0, ry = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 'R') { rx = i; ry = j; }
        int result = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto& d : dirs) {
            int x = rx + d[0], y = ry + d[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 'B') break;
                if (board[x][y] == 'p') { result++; break; }
                x += d[0]; y += d[1];
            }
        }
        return result;
    }
};
