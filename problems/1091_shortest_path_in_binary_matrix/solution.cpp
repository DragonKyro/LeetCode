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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<tuple<int,int,int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;
        while (!q.empty()) {
            auto [r, c, dist] = q.front(); q.pop();
            if (r == n-1 && c == n-1) return dist;
            for (int dr = -1; dr <= 1; dr++)
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r+dr, nc = c+dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc, dist+1});
                    }
                }
        }
        return -1;
    }
};
