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
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = INT_MIN;
        vector<vector<int>> mn(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i > 0) mn[i][j] = min(mn[i][j], mn[i-1][j]);
                if (j > 0) mn[i][j] = min(mn[i][j], mn[i][j-1]);
                res = max(res, grid[i][j] - mn[i][j]);
                mn[i][j] = min(mn[i][j], grid[i][j]);
            }
        return res;
    }
};
