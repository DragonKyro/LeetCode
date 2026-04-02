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
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[startRow][startColumn] = 1;
        long long result = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int move = 0; move < maxMove; move++) {
            vector<vector<long long>> newDp(m, vector<long long>(n, 0));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    if (!dp[i][j]) continue;
                    for (auto& d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) result = (result + dp[i][j]) % MOD;
                        else newDp[ni][nj] = (newDp[ni][nj] + dp[i][j]) % MOD;
                    }
                }
            dp = newDp;
        }
        return result;
    }
};
