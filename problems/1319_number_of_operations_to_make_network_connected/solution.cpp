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
    vector<int> parent;
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) return -1;
        parent.resize(n); iota(parent.begin(), parent.end(), 0);
        int components = n;
        for (auto& c : connections) {
            int pa = find(c[0]), pb = find(c[1]);
            if (pa != pb) { parent[pa] = pb; components--; }
        }
        return components - 1;
    }
};
