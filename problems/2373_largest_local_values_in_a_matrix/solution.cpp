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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n-2, vector<int>(n-2));
        for (int i = 0; i < n-2; i++)
            for (int j = 0; j < n-2; j++) {
                int mx = 0;
                for (int di = 0; di < 3; di++)
                    for (int dj = 0; dj < 3; dj++)
                        mx = max(mx, grid[i+di][j+dj]);
                result[i][j] = mx;
            }
        return result;
    }
};
