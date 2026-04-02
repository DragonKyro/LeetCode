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
    unordered_map<int, int> parent;
    int find(int x) {
        if (!parent.count(x)) parent[x] = x;
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y) { parent[find(x)] = find(y); }
public:
    int removeStones(vector<vector<int>>& stones) {
        for (auto& s : stones) unite(s[0], ~s[1]);
        unordered_set<int> roots;
        for (auto& s : stones) roots.insert(find(s[0]));
        return stones.size() - roots.size();
    }
};
