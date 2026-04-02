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
    void unite(int x, int y) { int px = find(x), py = find(y); if (px != py) parent[px] = py; }
    bool similar(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) if (a[i] != b[i] && ++diff > 2) return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n); iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++)
            if (similar(strs[i], strs[j])) unite(i, j);
        unordered_set<int> groups;
        for (int i = 0; i < n; i++) groups.insert(find(i));
        return groups.size();
    }
};
