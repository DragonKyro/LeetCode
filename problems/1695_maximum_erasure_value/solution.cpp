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
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, currSum = 0, maxSum = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currSum -= nums[left++];
            }
            seen.insert(nums[right]);
            currSum += nums[right];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
