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
        int res = 0;
        for (int c = 0; c < k; c++) {
            vector<int> dp(k, 0);
            for (int x : nums) {
                int r = x % k;
                int need = (c - r + k) % k;
                dp[r] = dp[need] + 1;
                res = max(res, dp[r]);
            }
        }
        return res;
    }
};
