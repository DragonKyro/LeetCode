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
    int strangePrinter(string s) {
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] != s[i-1]) t += s[i];
        }
        int n = t.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i+1][j] + 1;
                for (int k = i + 1; k <= j; k++) {
                    if (t[k] == t[i]) {
                        dp[i][j] = min(dp[i][j], (i+1 <= k-1 ? dp[i+1][k-1] : 0) + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
