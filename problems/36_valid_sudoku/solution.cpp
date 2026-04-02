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
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {}, cols[9][9] = {}, boxes[9][9] = {};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int d = board[i][j] - '1';
                int box = (i / 3) * 3 + j / 3;
                if (rows[i][d] || cols[j][d] || boxes[box][d]) return false;
                rows[i][d] = cols[j][d] = boxes[box][d] = true;
            }
        }
        return true;
    }
};
