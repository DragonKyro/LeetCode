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
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], current = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            current = max(nums[i], current + nums[i]);
            maxSum = max(maxSum, current);
        }
        return maxSum;
    }
};
