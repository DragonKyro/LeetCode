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
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        function<int(int,int)> dfs = [&](int r, int c) -> int {
            if (r<0||r>=m||c<0||c>=n||grid[r][c]==0) return 0;
            int f = grid[r][c]; grid[r][c] = 0;
            return f + dfs(r+1,c)+dfs(r-1,c)+dfs(r,c+1)+dfs(r,c-1);
        };
        for (int r=0;r<m;r++) for (int c=0;c<n;c++) ans = max(ans, dfs(r,c));
        return ans;
    }
};
