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
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                bool eq = true;
                for (int k = 0; k < n; k++)
                    if (grid[i][k] != grid[k][j]) { eq = false; break; }
                if (eq) count++;
            }
        return count;
    }
};
