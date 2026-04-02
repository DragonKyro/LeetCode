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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path = {0};
        dfs(graph, 0, path, result);
        return result;
    }

    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        if (node == (int)graph.size() - 1) { result.push_back(path); return; }
        for (int nei : graph[node]) {
            path.push_back(nei);
            dfs(graph, nei, path, result);
            path.pop_back();
        }
    }
};
