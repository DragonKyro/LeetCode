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
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            vector<int> newDp(target + 1, 0);
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k && face <= j; face++) {
                    newDp[j] = (newDp[j] + dp[j - face]) % MOD;
                }
            }
            dp = newDp;
        }
        return dp[target];
    }
};
