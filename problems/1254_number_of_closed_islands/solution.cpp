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
    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        if (grid[r][c] == 1) return true;
        grid[r][c] = 1;
        bool a = dfs(grid,r+1,c), b = dfs(grid,r-1,c), cc = dfs(grid,r,c+1), d = dfs(grid,r,c-1);
        return a && b && cc && d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0 && dfs(grid, i, j)) count++;
        return count;
    }
};
