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
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums[0];
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < (int)nums.size(); right++) {
                while (nums[right] - nums[left] > mid) left++;
                count += right - left;
            }
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
