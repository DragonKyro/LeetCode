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
    int countPartitions(vector<int>& nums, int k) {
        long long MOD=1e9+7, sum=accumulate(nums.begin(),nums.end(),0LL);
        if (sum < 2LL*k) return 0;
        vector<long long> dp(k,0); dp[0]=1;
        long long total=1;
        for (int num:nums) {
            total=total*2%MOD;
            for (int j=k-1;j>=num;j--) dp[j]=(dp[j]+dp[j-num])%MOD;
        }
        long long bad=0;
        for (long long d:dp) bad=(bad+d)%MOD;
        return (total-bad*2%MOD+MOD)%MOD;
    }
};
