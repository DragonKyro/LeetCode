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
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<void(int,int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
            grid[i][j] = 0;
            dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1);
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1)
                    dfs(i, j);
        int count = 0;
        for (auto& row : grid) for (int v : row) count += v;
        return count;
    }
};
