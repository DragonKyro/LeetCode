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
    int racecar(int target) {
        vector<int> dp(target + 1, 0);
        for (int t = 1; t <= target; t++) {
            int k = 32 - __builtin_clz(t);
            if ((1 << k) - 1 == t) { dp[t] = k; continue; }
            dp[t] = k + 1 + dp[(1 << k) - 1 - t];
            for (int j = 0; j < k - 1; j++)
                dp[t] = min(dp[t], k + j + 1 + dp[t - (1 << (k - 1)) + (1 << j)]);
        }
        return dp[target];
    }
};
