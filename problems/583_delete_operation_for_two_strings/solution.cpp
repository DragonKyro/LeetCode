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
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            vector<int> newDp(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) newDp[j] = dp[j-1] + 1;
                else newDp[j] = max(dp[j], newDp[j-1]);
            }
            dp = newDp;
        }
        return m + n - 2 * dp[n];
    }
};
