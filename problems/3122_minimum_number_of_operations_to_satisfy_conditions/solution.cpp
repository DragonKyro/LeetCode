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
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> freq(n, vector<int>(10, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                freq[j][grid[i][j]]++;
        vector<vector<int>> dp(n, vector<int>(10, INT_MAX));
        for (int d = 0; d < 10; d++) dp[0][d] = m - freq[0][d];
        for (int j = 1; j < n; j++)
            for (int d = 0; d < 10; d++) {
                int cost = m - freq[j][d];
                for (int pd = 0; pd < 10; pd++)
                    if (pd != d) dp[j][d] = min(dp[j][d], dp[j-1][pd] + cost);
            }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
