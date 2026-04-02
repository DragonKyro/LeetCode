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
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), xy = 0, xz = 0, yz = 0;
        for (int r = 0; r < n; r++) {
            int rowMax = 0, colMax = 0;
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0) xy++;
                rowMax = max(rowMax, grid[r][c]);
                colMax = max(colMax, grid[c][r]);
            }
            xz += rowMax; yz += colMax;
        }
        return xy + xz + yz;
    }
};
