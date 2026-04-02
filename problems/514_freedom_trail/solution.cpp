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
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        for (int k = m - 1; k >= 0; k--) {
            fill(dp[k].begin(), dp[k].end(), INT_MAX);
            for (int r = 0; r < n; r++) {
                for (int i = 0; i < n; i++) {
                    if (ring[i] == key[k]) {
                        int dist = min(abs(r - i), n - abs(r - i));
                        dp[k][r] = min(dp[k][r], dist + 1 + dp[k + 1][i]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
