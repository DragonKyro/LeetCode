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
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        bool found = false;
        for (int i = 0; i < n && !found; i++)
            for (int j = 0; j < n && !found; j++)
                if (grid[i][j] == 1) { dfs(grid, visited, q, i, j, n); found = true; }
        int steps = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                        if (grid[nx][ny] == 1) return steps;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int,int>>& q, int i, int j, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) return;
        visited[i][j] = true;
        q.push({i, j});
        dfs(grid, visited, q, i+1, j, n);
        dfs(grid, visited, q, i-1, j, n);
        dfs(grid, visited, q, i, j+1, n);
        dfs(grid, visited, q, i, j-1, n);
    }
};
