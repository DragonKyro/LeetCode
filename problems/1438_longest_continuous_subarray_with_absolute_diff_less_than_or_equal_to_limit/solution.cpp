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
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int left = 0, res = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            while (!maxD.empty() && nums[right] > maxD.back()) maxD.pop_back();
            while (!minD.empty() && nums[right] < minD.back()) minD.pop_back();
            maxD.push_back(nums[right]);
            minD.push_back(nums[right]);
            while (maxD.front() - minD.front() > limit) {
                if (nums[left] == maxD.front()) maxD.pop_front();
                if (nums[left] == minD.front()) minD.pop_front();
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
