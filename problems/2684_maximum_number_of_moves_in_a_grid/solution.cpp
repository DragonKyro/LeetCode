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
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int c = n-2; c >= 0; c--)
            for (int r = 0; r < m; r++)
                for (int dr = -1; dr <= 1; dr++) {
                    int nr = r+dr;
                    if (nr>=0&&nr<m&&grid[nr][c+1]>grid[r][c])
                        dp[r][c] = max(dp[r][c], 1+dp[nr][c+1]);
                }
        int ans = 0;
        for (int r = 0; r < m; r++) ans = max(ans, dp[r][0]);
        return ans;
    }
};
