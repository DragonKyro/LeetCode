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
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = n; i >= g; i--)
                for (int j = minProfit; j >= 0; j--)
                    dp[i][min(j + p, minProfit)] = (dp[i][min(j + p, minProfit)] + dp[i - g][j]) % MOD;
        }
        int res = 0;
        for (int i = 0; i <= n; i++) res = (res + dp[i][minProfit]) % MOD;
        return res;
    }
};
