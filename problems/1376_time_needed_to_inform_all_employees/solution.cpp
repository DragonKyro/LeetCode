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
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < n; i++)
            if (manager[i] != -1) children[manager[i]].push_back(i);
        function<int(int)> dfs = [&](int node) -> int {
            int maxTime = 0;
            for (int child : children[node]) maxTime = max(maxTime, dfs(child));
            return informTime[node] + maxTime;
        };
        return dfs(headID);
    }
};
