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
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();
        vector<int> idx(k), ans(k);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return queries[a] < queries[b]; });
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[0][0] = true;
        int count = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i : idx) {
            while (!pq.empty() && get<0>(pq.top()) < queries[i]) {
                auto [val, r, c] = pq.top(); pq.pop(); count++;
                for (auto& d : dirs) { int nr=r+d[0], nc=c+d[1]; if (nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]) { vis[nr][nc]=true; pq.push({grid[nr][nc],nr,nc}); } }
            }
            ans[i] = count;
        }
        return ans;
    }
};
