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
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);
        iota(dp.begin(), dp.end(), 0);
        for (int center = 0; center < n; center++) {
            expand(s, center, center, dp);
            expand(s, center, center + 1, dp);
        }
        return dp[n - 1];
    }
    void expand(string& s, int left, int right, vector<int>& dp) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            dp[right] = min(dp[right], left > 0 ? dp[left - 1] + 1 : 0);
            left--;
            right++;
        }
    }
};
