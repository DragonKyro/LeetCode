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
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> hor(m, vector<int>(n, 0)), ver(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    hor[i][j] = j > 0 ? hor[i][j - 1] + 1 : 1;
                    ver[i][j] = i > 0 ? ver[i - 1][j] + 1 : 1;
                }
            }
        }
        int result = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int side = min(hor[i][j], ver[i][j]);
                while (side > result) {
                    if (ver[i][j - side + 1] >= side && hor[i - side + 1][j] >= side) {
                        result = side;
                        break;
                    }
                    side--;
                }
            }
        }
        return result * result;
    }
};
