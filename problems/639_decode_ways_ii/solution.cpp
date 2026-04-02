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
    int numDecodings(string s) {
        long MOD = 1e9 + 7;
        int n = s.size();
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : (s[0] == '0' ? 0 : 1);
        for (int i = 2; i <= n; i++) {
            char c = s[i - 1], p = s[i - 2];
            if (c == '*') dp[i] = 9 * dp[i - 1] % MOD;
            else if (c != '0') dp[i] = dp[i - 1];
            if (p == '*') {
                if (c == '*') dp[i] = (dp[i] + 15 * dp[i - 2]) % MOD;
                else if (c <= '6') dp[i] = (dp[i] + 2 * dp[i - 2]) % MOD;
                else dp[i] = (dp[i] + dp[i - 2]) % MOD;
            } else if (p == '1') {
                if (c == '*') dp[i] = (dp[i] + 9 * dp[i - 2]) % MOD;
                else dp[i] = (dp[i] + dp[i - 2]) % MOD;
            } else if (p == '2') {
                if (c == '*') dp[i] = (dp[i] + 6 * dp[i - 2]) % MOD;
                else if (c <= '6') dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }
        return dp[n] % MOD;
    }
};
