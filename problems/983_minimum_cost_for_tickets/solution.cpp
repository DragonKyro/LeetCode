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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> daySet(days.begin(), days.end());
        int last = days.back();
        vector<int> dp(last + 1, 0);
        for (int i = 1; i <= last; i++) {
            if (!daySet.count(i)) { dp[i] = dp[i - 1]; continue; }
            dp[i] = min({dp[i - 1] + costs[0],
                         dp[max(0, i - 7)] + costs[1],
                         dp[max(0, i - 30)] + costs[2]});
        }
        return dp[last];
    }
};
