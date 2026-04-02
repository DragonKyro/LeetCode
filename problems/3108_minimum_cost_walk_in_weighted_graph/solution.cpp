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
    vector<int> parent, rnk, cost;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    void unite(int a, int b, int w) {
        int ra = find(a), rb = find(b);
        if (ra == rb) { cost[ra] &= w; return; }
        if (rnk[ra] < rnk[rb]) swap(ra, rb);
        parent[rb] = ra;
        cost[ra] = cost[ra] & cost[rb] & w;
        if (rnk[ra] == rnk[rb]) rnk[ra]++;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n); rnk.resize(n, 0); cost.resize(n, (1<<30)-1);
        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) unite(e[0], e[1], e[2]);
        vector<int> res;
        for (auto& q : query) {
            if (q[0] == q[1]) res.push_back(0);
            else if (find(q[0]) != find(q[1])) res.push_back(-1);
            else res.push_back(cost[find(q[0])]);
        }
        return res;
    }
};
