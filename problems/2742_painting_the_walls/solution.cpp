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
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = n; j >= 1; j--)
                dp[j] = min(dp[j], dp[max(j-time[i]-1, 0)] + cost[i]);
        return dp[n];
    }
};
