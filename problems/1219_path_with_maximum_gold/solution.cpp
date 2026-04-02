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
    int m, n;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
        int val = grid[r][c]; grid[r][c] = 0;
        int best = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto& d : dirs) best = max(best, dfs(grid, r+d[0], c+d[1]));
        grid[r][c] = val;
        return val + best;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};
