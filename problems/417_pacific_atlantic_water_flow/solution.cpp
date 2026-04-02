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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n)), atlantic(m, vector<bool>(n));
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& visited) {
            visited[r][c] = true;
            int dirs[] = {0,1,0,-1,0};
            for (int d = 0; d < 4; d++) {
                int nr = r+dirs[d], nc = c+dirs[d+1];
                if (nr>=0&&nr<m&&nc>=0&&nc<n&&!visited[nr][nc]&&heights[nr][nc]>=heights[r][c])
                    dfs(nr, nc, visited);
            }
        };
        for (int i = 0; i < m; i++) { dfs(i, 0, pacific); dfs(i, n-1, atlantic); }
        for (int j = 0; j < n; j++) { dfs(0, j, pacific); dfs(m-1, j, atlantic); }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
        return result;
    }
};
