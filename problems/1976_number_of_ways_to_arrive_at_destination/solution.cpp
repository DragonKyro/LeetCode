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
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        vector<vector<pair<int, long long>>> graph(n);
        for (auto& r : roads) { graph[r[0]].push_back({r[1], r[2]}); graph[r[1]].push_back({r[0], r[2]}); }
        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0; ways[0] = 1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, t] : graph[u]) {
                if (d + t < dist[v]) { dist[v] = d + t; ways[v] = ways[u]; pq.push({dist[v], v}); }
                else if (d + t == dist[v]) ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[n - 1] % MOD;
    }
};
