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
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) return -1;
        int rowSum = 0, colSum = 0, rowSwaps = 0, colSwaps = 0;
        for (int i = 0; i < n; i++) {
            rowSum += board[0][i];
            colSum += board[i][0];
            if (board[0][i] != i % 2) rowSwaps++;
            if (board[i][0] != i % 2) colSwaps++;
        }
        if (rowSum < n/2 || rowSum > (n+1)/2) return -1;
        if (colSum < n/2 || colSum > (n+1)/2) return -1;
        if (n % 2 == 1) {
            if (rowSwaps % 2 == 1) rowSwaps = n - rowSwaps;
            if (colSwaps % 2 == 1) colSwaps = n - colSwaps;
        } else {
            rowSwaps = min(rowSwaps, n - rowSwaps);
            colSwaps = min(colSwaps, n - colSwaps);
        }
        return (rowSwaps + colSwaps) / 2;
    }
};
