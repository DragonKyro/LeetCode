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
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, currMax = 0, currMin = 0;
        for (int num : nums) {
            currMax = max(currMax + num, num);
            currMin = min(currMin + num, num);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        return max(maxSum, -minSum);
    }
};
