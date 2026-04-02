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
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int allKeys = 0, sr = 0, sc = 0;
        for (int r = 0; r < m; r++) for (int c = 0; c < n; c++) {
            if (grid[r][c] == '@') { sr = r; sc = c; }
            else if (grid[r][c] >= 'a' && grid[r][c] <= 'f') allKeys |= 1 << (grid[r][c] - 'a');
        }
        queue<tuple<int,int,int,int>> q;
        set<tuple<int,int,int>> visited;
        q.push({sr, sc, 0, 0});
        visited.insert({sr, sc, 0});
        int dirs[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            auto [r, c, keys, dist] = q.front(); q.pop();
            if (keys == allKeys) return dist;
            for (auto& d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr<0||nr>=m||nc<0||nc>=n||grid[nr][nc]=='#') continue;
                char ch = grid[nr][nc];
                int nk = keys;
                if (ch>='a'&&ch<='f') nk |= 1<<(ch-'a');
                else if (ch>='A'&&ch<='F'&&!(keys&(1<<(ch-'A')))) continue;
                if (!visited.count({nr,nc,nk})) { visited.insert({nr,nc,nk}); q.push({nr,nc,nk,dist+1}); }
            }
        }
        return -1;
    }
};
