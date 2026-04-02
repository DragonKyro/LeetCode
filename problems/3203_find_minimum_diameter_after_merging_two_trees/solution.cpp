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
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = diameter(edges1, edges1.size()+1);
        int d2 = diameter(edges2, edges2.size()+1);
        return max({d1, d2, (d1+1)/2 + (d2+1)/2 + 1});
    }
    int diameter(vector<vector<int>>& edges, int n) {
        if (n==1) return 0;
        vector<vector<int>> g(n);
        for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        auto [f1,x] = bfs(g,0,n);
        auto [f2,d] = bfs(g,f1,n);
        return d;
    }
    pair<int,int> bfs(vector<vector<int>>& g, int s, int n) {
        vector<int> dist(n,-1); dist[s]=0;
        queue<int> q; q.push(s); int far=s;
        while (!q.empty()) {
            int u=q.front(); q.pop();
            for (int v:g[u]) if (dist[v]==-1) { dist[v]=dist[u]+1; q.push(v); if (dist[v]>dist[far]) far=v; }
        }
        return {far, dist[far]};
    }
};
