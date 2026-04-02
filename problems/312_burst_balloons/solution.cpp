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
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> arr(n);
        arr[0] = arr[n - 1] = 1;
        for (int i = 0; i < (int)nums.size(); i++) arr[i + 1] = nums[i];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; len++) {
            for (int left = 0; left < n - len; left++) {
                int right = left + len;
                for (int k = left + 1; k < right; k++) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][k] + dp[k][right] + arr[left] * arr[k] * arr[right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
