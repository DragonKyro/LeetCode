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
    vector<int> parent, sz;
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (sz[px] < sz[py]) swap(px, py);
        parent[py] = px; sz[px] += sz[py];
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        int TOP = m * n;
        parent.resize(m * n + 1); sz.resize(m * n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        auto gridCopy = grid;
        for (auto& h : hits) gridCopy[h[0]][h[1]] = 0;
        for (int c = 0; c < n; c++) if (gridCopy[0][c] == 1) unite(c, TOP);
        for (int r = 1; r < m; r++) for (int c = 0; c < n; c++) {
            if (!gridCopy[r][c]) continue;
            if (gridCopy[r-1][c]) unite(r*n+c, (r-1)*n+c);
            if (c > 0 && gridCopy[r][c-1]) unite(r*n+c, r*n+c-1);
        }
        vector<int> result(hits.size(), 0);
        int dirs[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int k = hits.size()-1; k >= 0; k--) {
            int r = hits[k][0], c = hits[k][1];
            if (!grid[r][c]) continue;
            int prev = sz[find(TOP)];
            if (r == 0) unite(r*n+c, TOP);
            for (auto& d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0&&nr<m&&nc>=0&&nc<n&&gridCopy[nr][nc]) unite(r*n+c, nr*n+nc);
            }
            gridCopy[r][c] = 1;
            result[k] = max(0, sz[find(TOP)] - prev - 1);
        }
        return result;
    }
};
