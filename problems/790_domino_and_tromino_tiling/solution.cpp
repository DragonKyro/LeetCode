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
    int numTilings(int n) {
        long long MOD = 1e9 + 7;
        if (n <= 2) return n;
        vector<long long> dp(n + 1);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = (2 * dp[i-1] + dp[i-3]) % MOD;
        return dp[n];
    }
};
