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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> graph[2];
        graph[0].resize(n);
        graph[1].resize(n);
        for (auto& e : redEdges) graph[0][e[0]].push_back(e[1]);
        for (auto& e : blueEdges) graph[1][e[0]].push_back(e[1]);
        vector<int> result(n, -1);
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});
        visited[0][0] = visited[1][0] = true;
        while (!q.empty()) {
            auto [node, color, dist] = q.front();
            q.pop();
            if (result[node] == -1) result[node] = dist;
            int next = 1 - color;
            for (int nei : graph[next][node]) {
                if (!visited[next][nei]) {
                    visited[next][nei] = true;
                    q.push({nei, next, dist + 1});
                }
            }
        }
        return result;
    }
};
