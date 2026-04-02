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
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total + target) % 2 != 0 || abs(target) > total) return 0;
        int subsetSum = (total + target) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;
        for (int num : nums)
            for (int j = subsetSum; j >= num; j--)
                dp[j] += dp[j - num];
        return dp[subsetSum];
    }
};
