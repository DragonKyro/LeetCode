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
    int countOfPairs(vector<int>& nums) {
        int MOD = 1e9+7, n = nums.size();
        vector<long long> dp(nums[0]+1, 1);
        for (int i = 1; i < n; i++) {
            vector<long long> ndp(nums[i]+1, 0);
            long long prefix = 0;
            int k = 0;
            for (int j = 0; j <= nums[i]; j++) {
                int bound = min(j, nums[i-1]-nums[i]+j);
                while (k <= bound && k <= nums[i-1]) { prefix = (prefix+dp[k])%MOD; k++; }
                ndp[j] = prefix;
            }
            dp = ndp;
        }
        long long res = 0;
        for (long long v : dp) res = (res+v)%MOD;
        return res;
    }
};
