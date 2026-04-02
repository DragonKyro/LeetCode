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
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), target = (1 << n) - 1;
        queue<tuple<int,int,int>> q;
        set<pair<int,int>> visited;
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            visited.insert({i, 1 << i});
        }
        while (!q.empty()) {
            auto [node, mask, dist] = q.front(); q.pop();
            if (mask == target) return dist;
            for (int nei : graph[node]) {
                int newMask = mask | (1 << nei);
                if (!visited.count({nei, newMask})) {
                    visited.insert({nei, newMask});
                    q.push({nei, newMask, dist + 1});
                }
            }
        }
        return -1;
    }
};
