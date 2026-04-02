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
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> newDp(k + 1, 0);
            vector<long> prefix(k + 2, 0);
            for (int j = 0; j <= k; j++) prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            for (int j = 0; j <= k; j++) {
                newDp[j] = (prefix[j + 1] - prefix[max(0, j - i + 1)] + MOD) % MOD;
            }
            dp = newDp;
        }
        return dp[k];
    }
};
