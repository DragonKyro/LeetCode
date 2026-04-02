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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), result = 0;
        vector<int> rowMax(n, 0), colMax(n, 0);
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            rowMax[r] = max(rowMax[r], grid[r][c]);
            colMax[c] = max(colMax[c], grid[r][c]);
        }
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++)
            result += min(rowMax[r], colMax[c]) - grid[r][c];
        return result;
    }
};
