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
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0], maxDiff = -1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > minVal) maxDiff = max(maxDiff, nums[i] - minVal);
            minVal = min(minVal, nums[i]);
        }
        return maxDiff;
    }
};
