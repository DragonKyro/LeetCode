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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0}); visited[0][0] = true;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (r == n-1 && c == n-1) return t;
            for (auto& d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};
