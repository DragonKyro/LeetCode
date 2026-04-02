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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            auto [prob, node] = pq.top(); pq.pop();
            if (node == end_node) return prob;
            if (prob < dist[node]) continue;
            for (auto& [next, ep] : graph[node]) {
                double np = prob * ep;
                if (np > dist[next]) {
                    dist[next] = np;
                    pq.push({np, next});
                }
            }
        }
        return 0.0;
    }
};
