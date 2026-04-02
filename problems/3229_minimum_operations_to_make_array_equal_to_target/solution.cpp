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
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<long long> diff(n);
        for (int i = 0; i < n; i++) diff[i] = target[i] - nums[i];
        long long ops = abs(diff[0]);
        for (int i = 1; i < n; i++) {
            if (diff[i]>0 && diff[i-1]>0) ops += max(0LL, diff[i]-diff[i-1]);
            else if (diff[i]<0 && diff[i-1]<0) ops += max(0LL, -diff[i]+diff[i-1]);
            else ops += abs(diff[i]);
        }
        return ops;
    }
};
