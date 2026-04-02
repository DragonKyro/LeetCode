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
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int m = nums.size() / 2;
        long long ops = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= m && nums[i] > k) ops += nums[i] - k;
            else if (i >= m && nums[i] < k) ops += k - nums[i];
        }
        return ops;
    }
};
