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
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& e : edges) { graph[e[0]].push_back({e[1], e[2]}); graph[e[1]].push_back({e[0], e[2]}); }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : graph[u]) {
                int nd = d + w + 1;
                if (nd < dist[v]) { dist[v] = nd; pq.push({nd, v}); }
            }
        }
        int result = 0;
        for (int d : dist) if (d <= maxMoves) result++;
        for (auto& e : edges) {
            int a = dist[e[0]] <= maxMoves ? max(0, maxMoves - dist[e[0]]) : 0;
            int b = dist[e[1]] <= maxMoves ? max(0, maxMoves - dist[e[1]]) : 0;
            result += min(a + b, e[2]);
        }
        return result;
    }
};
