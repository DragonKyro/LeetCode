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
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> suf(n+1, 0);
        for (int i=n-1;i>=0;i--) suf[i]=suf[i+1]|nums[i];
        long long ans=0, pre=0;
        for (int i=0;i<n;i++) {
            ans = max(ans, pre|((long long)nums[i]<<k)|suf[i+1]);
            pre |= nums[i];
        }
        return ans;
    }
};
