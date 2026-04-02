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
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) if (grid[i][0] == 0)
            for (int j = 0; j < n; j++) grid[i][j] ^= 1;
        for (int j = 1; j < n; j++) {
            int ones = 0;
            for (int i = 0; i < m; i++) ones += grid[i][j];
            if (ones < m - ones)
                for (int i = 0; i < m; i++) grid[i][j] ^= 1;
        }
        int result = 0;
        for (auto& row : grid) {
            int val = 0;
            for (int b : row) val = val * 2 + b;
            result += val;
        }
        return result;
    }
};
