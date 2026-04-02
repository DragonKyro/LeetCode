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
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for (int i=0;i<n;i++) pre[i+1]=pre[i]+nums[i];
        vector<long long> ans;
        for (int q : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long left = (long long)q*idx - pre[idx];
            long long right = (pre[n]-pre[idx]) - (long long)q*(n-idx);
            ans.push_back(left+right);
        }
        return ans;
    }
};
