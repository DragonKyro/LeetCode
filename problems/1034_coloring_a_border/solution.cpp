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
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size(), orig = grid[row][col];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> borders;
        function<void(int,int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] != orig) return;
            visited[i][j] = true;
            if (i == 0 || i == m-1 || j == 0 || j == n-1 ||
                grid[i-1][j] != orig || grid[i+1][j] != orig || grid[i][j-1] != orig || grid[i][j+1] != orig)
                borders.push_back({i, j});
            dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1);
        };
        dfs(row, col);
        for (auto [r,c] : borders) grid[r][c] = color;
        return grid;
    }
};
