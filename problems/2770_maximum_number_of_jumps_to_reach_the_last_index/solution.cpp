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
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1); dp[0] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (dp[j] != -1 && abs(nums[i]-nums[j]) <= target)
                    dp[i] = max(dp[i], dp[j]+1);
        return dp[n-1];
    }
};
