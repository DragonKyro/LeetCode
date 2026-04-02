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
    int res = 0;
    vector<vector<int>> g;
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        g.resize(n);
        for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        dfs(0, -1);
        return res;
    }
    int dfs(int u, int p) {
        vector<int> sizes;
        int total = 1;
        for (int v : g[u]) {
            if (v != p) { int sz = dfs(v, u); sizes.push_back(sz); total += sz; }
        }
        if (sizes.empty() || set<int>(sizes.begin(),sizes.end()).size() == 1) res++;
        return total;
    }
};
