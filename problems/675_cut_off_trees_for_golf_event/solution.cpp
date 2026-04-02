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
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<array<int,3>> trees;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
        sort(trees.begin(), trees.end());
        auto bfs = [&](int sr, int sc, int tr, int tc) -> int {
            if (sr == tr && sc == tc) return 0;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<array<int,3>> q;
            q.push({sr, sc, 0});
            visited[sr][sc] = true;
            int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            while (!q.empty()) {
                auto [r, c, dist] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && forest[nr][nc] > 0) {
                        if (nr == tr && nc == tc) return dist + 1;
                        visited[nr][nc] = true;
                        q.push({nr, nc, dist + 1});
                    }
                }
            }
            return -1;
        };
        int sr = 0, sc = 0, total = 0;
        for (auto& t : trees) {
            int steps = bfs(sr, sc, t[1], t[2]);
            if (steps == -1) return -1;
            total += steps;
            sr = t[1]; sc = t[2];
        }
        return total;
    }
};
