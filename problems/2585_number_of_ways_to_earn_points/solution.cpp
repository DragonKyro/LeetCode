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
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int MOD = 1e9+7;
        vector<long long> dp(target+1, 0); dp[0] = 1;
        for (auto& t : types)
            for (int j = target; j >= 0; j--)
                for (int k = 1; k <= t[0]; k++)
                    if (j - k*t[1] >= 0) dp[j] = (dp[j] + dp[j-k*t[1]]) % MOD;
        return dp[target];
    }
};
