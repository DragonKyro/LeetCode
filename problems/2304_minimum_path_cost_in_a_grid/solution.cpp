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
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(grid[0].begin(), grid[0].end());
        for (int i = 1; i < m; i++) {
            vector<int> newDp(n, INT_MAX);
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    newDp[j] = min(newDp[j], dp[k] + moveCost[grid[i-1][k]][j] + grid[i][j]);
            dp = newDp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
