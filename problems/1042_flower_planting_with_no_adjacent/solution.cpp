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
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (auto& p : paths) { graph[p[0]-1].push_back(p[1]-1); graph[p[1]-1].push_back(p[0]-1); }
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            set<int> used;
            for (int j : graph[i]) used.insert(result[j]);
            for (int c = 1; c <= 4; c++) {
                if (!used.count(c)) { result[i] = c; break; }
            }
        }
        return result;
    }
};
