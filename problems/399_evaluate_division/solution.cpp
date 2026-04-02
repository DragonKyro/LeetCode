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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> res;
        for (auto& q : queries)
            res.push_back(bfs(graph, q[0], q[1]));
        return res;
    }
    double bfs(unordered_map<string, unordered_map<string, double>>& graph, string src, string dst) {
        if (!graph.count(src) || !graph.count(dst)) return -1.0;
        if (src == dst) return 1.0;
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({src, 1.0});
        visited.insert(src);
        while (!q.empty()) {
            auto [node, product] = q.front(); q.pop();
            if (node == dst) return product;
            for (auto& [neighbor, val] : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push({neighbor, product * val});
                }
            }
        }
        return -1.0;
    }
};
