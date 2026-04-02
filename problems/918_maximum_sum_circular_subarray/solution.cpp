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
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = INT_MIN, curMax = 0;
        int minSum = INT_MAX, curMin = 0;
        for (int num : nums) {
            total += num;
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
        }
        return maxSum < 0 ? maxSum : max(maxSum, total - minSum);
    }
};
