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
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (auto& r : richer) graph[r[1]].push_back(r[0]);
        vector<int> answer(n, -1);
        function<int(int)> dfs = [&](int node) -> int {
            if (answer[node] != -1) return answer[node];
            answer[node] = node;
            for (int nei : graph[node]) {
                int cand = dfs(nei);
                if (quiet[cand] < quiet[answer[node]]) answer[node] = cand;
            }
            return answer[node];
        };
        for (int i = 0; i < n; i++) dfs(i);
        return answer;
    }
};
