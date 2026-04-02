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
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1, inc = 1, dec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) { inc++; dec = 1; }
            else if (nums[i] < nums[i-1]) { dec++; inc = 1; }
            else { inc = 1; dec = 1; }
            res = max(res, max(inc, dec));
        }
        return res;
    }
};
