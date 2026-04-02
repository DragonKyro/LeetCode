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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int i) {
            visited[i] = true;
            for (int j = 0; j < n; j++)
                if (isConnected[i][j] && !visited[j]) dfs(j);
        };
        for (int i = 0; i < n; i++)
            if (!visited[i]) { dfs(i); count++; }
        return count;
    }
};
