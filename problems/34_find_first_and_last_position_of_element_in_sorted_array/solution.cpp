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
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (left >= nums.size() || nums[left] != target) return {-1, -1};
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {left, right};
    }
};
