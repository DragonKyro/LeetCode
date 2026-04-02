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
    vector<int> parent, sz;
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (sz[px] < sz[py]) swap(px, py);
        parent[py] = px; sz[px] += sz[py];
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n); sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) unite(e[0], e[1]);
        long long total = 0, remaining = n;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) { remaining -= sz[i]; total += (long long)sz[i] * remaining; }
        }
        return total;
    }
};
