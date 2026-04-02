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
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(), res = 1;
        vector<vector<int>> dp(n, vector<int>(k+1, 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++) {
                for (int p = 0; p < i; p++) {
                    if (nums[p]==nums[i]) dp[i][j]=max(dp[i][j],dp[p][j]+1);
                    else if (j>0) dp[i][j]=max(dp[i][j],dp[p][j-1]+1);
                }
                res = max(res, dp[i][j]);
            }
        return res;
    }
};
