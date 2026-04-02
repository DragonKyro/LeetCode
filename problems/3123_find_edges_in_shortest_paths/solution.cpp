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
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], edges[i][2], i});
            g[edges[i][1]].push_back({edges[i][0], edges[i][2], i});
        }
        auto dijk = [&](int src) {
            vector<long long> dist(n, LLONG_MAX);
            dist[src] = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            pq.push({0, src});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto [v, w, _] : g[u])
                    if (d + w < dist[v]) { dist[v] = d + w; pq.push({dist[v], v}); }
            }
            return dist;
        };
        auto d0 = dijk(0), dn = dijk(n-1);
        vector<bool> res(edges.size(), false);
        if (d0[n-1] == LLONG_MAX) return res;
        for (int i = 0; i < edges.size(); i++) {
            int u=edges[i][0], v=edges[i][1], w=edges[i][2];
            if (d0[u]+w+dn[v]==d0[n-1] || d0[v]+w+dn[u]==d0[n-1]) res[i]=true;
        }
        return res;
    }
};
