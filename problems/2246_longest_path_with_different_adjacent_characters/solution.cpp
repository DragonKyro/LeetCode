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
    int ans = 1;
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);
        dfs(0, children, s);
        return ans;
    }
    int dfs(int node, vector<vector<int>>& children, string& s) {
        int top1 = 0, top2 = 0;
        for (int child : children[node]) {
            int len = dfs(child, children, s);
            if (s[child] != s[node]) {
                if (len > top1) { top2 = top1; top1 = len; }
                else if (len > top2) top2 = len;
            }
        }
        ans = max(ans, top1 + top2 + 1);
        return top1 + 1;
    }
};
