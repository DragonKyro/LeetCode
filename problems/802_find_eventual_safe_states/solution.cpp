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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (dfs(graph, color, i)) result.push_back(i);
        }
        return result;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node) {
        if (color[node] != 0) return color[node] == 2;
        color[node] = 1;
        for (int nei : graph[node]) {
            if (!dfs(graph, color, nei)) return false;
        }
        color[node] = 2;
        return true;
    }
};
