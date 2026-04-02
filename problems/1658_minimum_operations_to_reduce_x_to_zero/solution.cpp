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
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for (int num : nums) target += num;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        int n = nums.size(), maxLen = -1, currSum = 0, left = 0;
        for (int right = 0; right < n; right++) {
            currSum += nums[right];
            while (currSum > target) currSum -= nums[left++];
            if (currSum == target) maxLen = max(maxLen, right - left + 1);
        }
        return maxLen == -1 ? -1 : n - maxLen;
    }
};
