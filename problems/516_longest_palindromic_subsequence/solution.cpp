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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> newDp(n, 0);
            newDp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) newDp[j] = dp[j - 1] + 2;
                else newDp[j] = max(dp[j], newDp[j - 1]);
            }
            dp = newDp;
        }
        return dp[n - 1];
    }
};
