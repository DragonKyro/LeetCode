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
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0;
        int moves[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
        for (int step = 0; step < k; step++) {
            vector<vector<double>> newDp(n, vector<double>(n, 0.0));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] > 0) {
                        for (auto& m : moves) {
                            int nr = r + m[0], nc = c + m[1];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                                newDp[nr][nc] += dp[r][c] / 8.0;
                            }
                        }
                    }
                }
            }
            dp = newDp;
        }
        double sum = 0;
        for (auto& row2 : dp) for (double v : row2) sum += v;
        return sum;
    }
};
