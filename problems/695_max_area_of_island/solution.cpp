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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        function<int(int,int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
            grid[i][j] = 0;
            return 1 + dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1);
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) maxArea = max(maxArea, dfs(i, j));
        return maxArea;
    }
};
