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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), total = m * n;
        k %= total;
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < total; i++) {
            int ni = (i + k) % total;
            res[ni/n][ni%n] = grid[i/n][i%n];
        }
        return res;
    }
};
