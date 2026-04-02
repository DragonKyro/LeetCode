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
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], 0});
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto& [next, cost] : graph[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    count += cost;
                    q.push(next);
                }
            }
        }
        return count;
    }
};
