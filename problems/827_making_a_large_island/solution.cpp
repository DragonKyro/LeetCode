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
    int n;
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        if (r<0||r>=n||c<0||c>=n||grid[r][c]!=1) return 0;
        grid[r][c] = id;
        return 1 + dfs(grid,r+1,c,id) + dfs(grid,r-1,c,id) + dfs(grid,r,c+1,id) + dfs(grid,r,c-1,id);
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int,int> sizes;
        int id = 2;
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++)
            if (grid[r][c] == 1) { sizes[id] = dfs(grid, r, c, id); id++; }
        int result = 0;
        for (auto& [k,v] : sizes) result = max(result, v);
        int dirs[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            if (grid[r][c] != 0) continue;
            unordered_set<int> seen;
            int total = 1;
            for (auto& d : dirs) {
                int nr=r+d[0], nc=c+d[1];
                if (nr>=0&&nr<n&&nc>=0&&nc<n&&seen.insert(grid[nr][nc]).second)
                    total += sizes.count(grid[nr][nc]) ? sizes[grid[nr][nc]] : 0;
            }
            result = max(result, total);
        }
        return result;
    }
};
