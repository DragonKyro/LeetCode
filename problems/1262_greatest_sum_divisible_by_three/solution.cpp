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
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for (int x : nums) {
            auto temp = dp;
            for (int i = 0; i < 3; i++)
                dp[(i + x) % 3] = max(dp[(i + x) % 3], temp[i] + x);
        }
        return dp[0];
    }
};
