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
    int maxProduct(vector<int>& nums) {
        int res = nums[0], curMax = 1, curMin = 1;
        for (int n : nums) {
            int a = n * curMax, b = n * curMin;
            curMax = max({n, a, b});
            curMin = min({n, a, b});
            res = max(res, curMax);
        }
        return res;
    }
};
