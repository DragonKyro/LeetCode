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
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), total = accumulate(nums.begin(), nums.end(), 0);
        if (n == 1) return false;
        int half = n / 2;
        vector<unordered_set<int>> dp(half + 1);
        dp[0].insert(0);
        for (int num : nums) {
            for (int k = half; k >= 1; k--) {
                for (int s : dp[k - 1]) dp[k].insert(s + num);
            }
        }
        for (int k = 1; k <= half; k++) {
            if (total * k % n == 0 && dp[k].count(total * k / n)) return true;
        }
        return false;
    }
};
