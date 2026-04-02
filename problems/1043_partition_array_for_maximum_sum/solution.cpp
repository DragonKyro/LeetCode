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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int mx = 0;
            for (int j = 1; j <= min(k, i); j++) {
                mx = max(mx, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + mx * j);
            }
        }
        return dp[n];
    }
};
