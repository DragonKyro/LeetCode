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
    int checkRecord(int n) {
        int MOD = 1e9 + 7;
        long long dp[2][3] = {};
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            long long newDp[2][3] = {};
            for (int a = 0; a < 2; a++)
                for (int l = 0; l < 3; l++) {
                    if (!dp[a][l]) continue;
                    newDp[a][0] = (newDp[a][0] + dp[a][l]) % MOD;
                    if (a < 1) newDp[a+1][0] = (newDp[a+1][0] + dp[a][l]) % MOD;
                    if (l < 2) newDp[a][l+1] = (newDp[a][l+1] + dp[a][l]) % MOD;
                }
            memcpy(dp, newDp, sizeof(dp));
        }
        long long res = 0;
        for (int a = 0; a < 2; a++)
            for (int l = 0; l < 3; l++) res = (res + dp[a][l]) % MOD;
        return res;
    }
};
