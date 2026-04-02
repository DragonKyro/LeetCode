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
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(n);
        for (int col = 0; col < n; col++) {
            int c = col;
            bool stuck = false;
            for (int row = 0; row < m; row++) {
                int nc = c + grid[row][c];
                if (nc < 0 || nc >= n || grid[row][nc] != grid[row][c]) {
                    stuck = true;
                    break;
                }
                c = nc;
            }
            result[col] = stuck ? -1 : c;
        }
        return result;
    }
};
