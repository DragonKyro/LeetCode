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
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++)
                if (grid[i][j] != grid[0][j]) return false;
            if (j+1 < n && grid[0][j] == grid[0][j+1]) return false;
        }
        return true;
    }
};
