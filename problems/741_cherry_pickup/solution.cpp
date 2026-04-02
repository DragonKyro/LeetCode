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
    int n;
    vector<vector<vector<int>>> memo;

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, dp(grid, 0, 0, 0));
    }

    int dp(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) return -999999;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -999999;
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if (memo[r1][c1][r2] != INT_MIN) return memo[r1][c1][r2];
        int cherries = grid[r1][c1];
        if (r1 != r2) cherries += grid[r2][c2];
        cherries += max({dp(grid,r1+1,c1,r2+1), dp(grid,r1+1,c1,r2), dp(grid,r1,c1+1,r2+1), dp(grid,r1,c1+1,r2)});
        return memo[r1][c1][r2] = cherries;
    }
};
