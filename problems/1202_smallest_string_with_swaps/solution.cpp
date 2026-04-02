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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& p : pairs) unite(p[0], p[1]);
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[find(i)].push_back(i);
        for (auto& [root, indices] : groups) {
            string chars;
            for (int i : indices) chars += s[i];
            sort(chars.begin(), chars.end());
            sort(indices.begin(), indices.end());
            for (int i = 0; i < (int)indices.size(); i++) s[indices[i]] = chars[i];
        }
        return s;
    }
};
