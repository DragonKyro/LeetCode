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
    vector<vector<int>> graph;
    vector<int> count, ans;
    int n;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n); count.assign(n, 1); ans.assign(n, 0);
        for (auto& e : edges) { graph[e[0]].push_back(e[1]); graph[e[1]].push_back(e[0]); }
        dfs(0, -1); dfs2(0, -1);
        return ans;
    }
    void dfs(int node, int parent) {
        for (int child : graph[node]) if (child != parent) {
            dfs(child, node);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }
    void dfs2(int node, int parent) {
        for (int child : graph[node]) if (child != parent) {
            ans[child] = ans[node] - count[child] + (n - count[child]);
            dfs2(child, node);
        }
    }
};
