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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> cand1, cand2;
        for (auto& e : edges) {
            if (parent[e[1]] != 0) {
                cand1 = {parent[e[1]], e[1]};
                cand2 = {e[0], e[1]};
                break;
            }
            parent[e[1]] = e[0];
        }
        vector<int> root(n + 1);
        iota(root.begin(), root.end(), 0);
        function<int(int)> find = [&](int x) -> int {
            while (root[x] != x) { root[x] = root[root[x]]; x = root[x]; }
            return x;
        };
        for (auto& e : edges) {
            if (!cand2.empty() && e[0] == cand2[0] && e[1] == cand2[1]) continue;
            int pu = find(e[0]), pv = find(e[1]);
            if (pu == pv) return cand1.empty() ? e : cand1;
            root[pv] = pu;
        }
        return cand2;
    }
};
