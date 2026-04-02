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
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), result = 0;
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            if (grid[r][c] > 0) {
                result += 2 + 4 * grid[r][c];
                if (r > 0) result -= 2 * min(grid[r][c], grid[r-1][c]);
                if (c > 0) result -= 2 * min(grid[r][c], grid[r][c-1]);
            }
        }
        return result;
    }
};
