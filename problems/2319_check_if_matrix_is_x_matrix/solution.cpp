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
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) { if (grid[i][j] == 0) return false; }
                else { if (grid[i][j] != 0) return false; }
            }
        return true;
    }
};
