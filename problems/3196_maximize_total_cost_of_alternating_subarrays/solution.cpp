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
    long long maximumTotalCost(vector<int>& nums) {
        long long pos = nums[0], neg = LLONG_MIN/2;
        for (int i = 1; i < nums.size(); i++) {
            long long np = max(pos,neg) + nums[i];
            long long nn = pos - nums[i];
            pos = np; neg = nn;
        }
        return max(pos, neg);
    }
};
