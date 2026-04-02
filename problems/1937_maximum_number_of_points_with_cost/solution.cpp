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
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(n);
        for (int j = 0; j < n; j++) dp[j] = points[0][j];
        for (int i = 1; i < m; i++) {
            vector<long long> left(n), right(n);
            left[0] = dp[0];
            for (int j = 1; j < n; j++) left[j] = max(left[j - 1] - 1, dp[j]);
            right[n - 1] = dp[n - 1];
            for (int j = n - 2; j >= 0; j--) right[j] = max(right[j + 1] - 1, dp[j]);
            for (int j = 0; j < n; j++) dp[j] = points[i][j] + max(left[j], right[j]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
