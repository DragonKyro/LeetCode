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
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rowCost = 0, colCost = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n/2; j++)
                if (grid[i][j] != grid[i][n-1-j]) rowCost++;
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m/2; i++)
                if (grid[i][j] != grid[m-1-i][j]) colCost++;
        return min(rowCost, colCost);
    }
};
